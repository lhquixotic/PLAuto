import numpy as np
import rospy
from easydict import EasyDict as edict
from threading import Lock
import copy

from plauto_cognition_msgs.msg import LaneState, MapState, RoadObstacle
from plauto_cognition_msgs.utils import convert_tracking_box
from plauto_cognition_msgs.utils import default_msg as cognition_default
from plauto_common.geometry import dist_from_point_to_polyline2d, wrap_angle
from plauto_common.kinematics import get_frenet_state
from plauto_nav_msgs.msg import RigidBodyStateStamped
from plauto_nav_msgs.utils import get_speed, get_yaw
from plauto_nav_msgs.msg import Lane, Map
from plauto_nav_msgs.utils import get_lane_array, default_msg as navigation_default
from plauto_perception_msgs.msg import (DetectionBoxArray, ObjectSignals,
                                     TrackingBoxArray)

class NearestLocator:
    def __init__(self, lane_dist_thres=5):
        
        self._static_map_lock = Lock()
        self._static_map_buffer = None

        self._ego_vehicle_state_lock = Lock()
        self._ego_vehicle_state_buffer = None

        self._surrounding_object_list_lock = Lock()
        self._surrounding_object_list_buffer = None

        self._traffic_light_detection_lock = Lock()
        self._traffic_light_detection_buffer = None
        
        self._lane_dist_thres = lane_dist_thres

        # These two are buffers for computation
        self._ego_vehicle_distance_to_lane_head = [] # distance from vehicle to lane start
        self._ego_vehicle_distance_to_lane_tail = [] # distance from vehicle to lane end

    # ====== Data Receiver =======

    def receive_static_map(self, static_map):
        assert type(static_map) == Map
        with self._static_map_lock:
            self._static_map_buffer = static_map
            # print("recved: ", static_map)
            # rospy.loginfo("Updated Local Static Map: lanes_num = %d, in_junction = %d, target_lane_index = %d",
            #    len(static_map.lanes), int(static_map.in_junction), static_map.target_lane_index)

    def receive_object_list(self, object_list):
        assert type(object_list) == TrackingBoxArray
        with self._surrounding_object_list_lock:
            if self._ego_vehicle_state_buffer != None:
                self._surrounding_object_list_buffer = convert_tracking_box(object_list, self._ego_vehicle_state_buffer)

    def receive_ego_state(self, state):
        assert type(state) == RigidBodyStateStamped
        with self._ego_vehicle_state_lock:
            self._ego_vehicle_state_buffer = state
            # rospy.loginfo("Update ego state: x = %f, y = %f",state.state.pose.pose.position.x,state.state.pose.pose.position.y)

    def receive_traffic_light_detection(self, detection):
        assert type(detection) == DetectionBoxArray
        with self._traffic_light_detection_lock:
            self._traffic_light_detection_buffer = detection

    # ====== Data Updator =======
    
    def update(self):
        # All transient states collected for this update:
        # - ego_state
        # - static_map
        # - dynamic_map
        # - static_map_lane_path_array
        # - static_map_lane_tangets
        # - surrounding_object_list
        tstates = edict()

        # Skip if not ready
        if not self._ego_vehicle_state_buffer:
            return None

        with self._ego_vehicle_state_lock:
            tstates.ego_state = copy.deepcopy(self._ego_vehicle_state_buffer) 

        # Update buffer information
        tstates.surrounding_object_list = copy.deepcopy(self._surrounding_object_list_buffer or [])

        tstates.static_map = copy.deepcopy(self._static_map_buffer or navigation_default(Map)) 
        static_map = tstates.static_map # for easier access
        # print("static_map",tstates.static_map.lanes)
        tstates.static_map_lane_path_array = get_lane_array(tstates.static_map.lanes)
        tstates.static_map_lane_tangets = [[point.tangent for point in lane.central_path_points] for lane in tstates.static_map.lanes]
        tstates.dynamic_map = cognition_default(MapState)
        dynamic_map = tstates.dynamic_map # for easier access

        # Create dynamic maps and add static map elements
        dynamic_map.header.frame_id = "map"
        dynamic_map.header.stamp = rospy.Time.now()
        dynamic_map.ego_state = tstates.ego_state.state

        if static_map.in_junction or len(static_map.lanes) == 0:
            rospy.logdebug("In junction due to static map report junction location")
            dynamic_map.model = MapState.MODEL_JUNCTION_MAP
            dynamic_map.jmap.drivable_area = static_map.drivable_area
        else:
            dynamic_map.model = MapState.MODEL_MULTILANE_MAP
            for lane in static_map.lanes:
                dlane = cognition_default(LaneState)
                dlane.map_lane = lane
                dynamic_map.mmap.lanes.append(dlane)
            dynamic_map.mmap.target_lane_index = static_map.target_lane_index

        # Locate vehicles onto the junction map
        # TODO: Calculate frenet coordinate for objects in here or in put_buffer?
        self.locate_objects_in_junction(tstates)

        # Locate vehicles onto the multilane map
        if dynamic_map.model == MapState.MODEL_MULTILANE_MAP:
            self.locate_ego_vehicle_in_lanes(tstates)
            self.locate_surrounding_objects_in_lanes(tstates)
            self.locate_stop_sign_in_lanes(tstates)
            self.locate_speed_limit_in_lanes(tstates)

        rospy.logdebug("Updated Dynamic Map: lanes_num = %d, in_junction = %s, lane_index = %.2f, distance_to_end = %f",
            len(dynamic_map.mmap.lanes), str(dynamic_map.model == MapState.MODEL_JUNCTION_MAP),
            dynamic_map.mmap.ego_lane_index, dynamic_map.mmap.distance_to_junction)

        return dynamic_map

    # ========= For in lane =========

    def locate_object_in_lane(self, object_state, tstates, dist_list=None):
        '''
        Calculate (continuous) lane index for a object.
        Parameters: dist_list is the distance buffer. If not provided, it will be calculated
        '''

        if not dist_list:
            dist_list = np.array([dist_from_point_to_polyline2d(
                object_state.pose.pose.position.x,
                object_state.pose.pose.position.y,
                lane) for lane in tstates.static_map_lane_path_array])
        
        # Check if there's only two lanes
        if len(tstates.dynamic_map.mmap.lanes) < 2:
            closest_lane = second_closest_lane = 0
        else:
            closest_lane, second_closest_lane = np.abs(dist_list[:, 0]).argsort()[:2]

        # Signed distance from target to two closest lane
        closest_lane_dist, second_closest_lane_dist = dist_list[closest_lane, 0], dist_list[second_closest_lane, 0]

        if abs(closest_lane_dist) > self._lane_dist_thres:
            return -1 # TODO: return reasonable value

        # Judge whether the point is outside of lanes
        if closest_lane == second_closest_lane or closest_lane_dist * second_closest_lane_dist > 0:
            # The object is at left or right most
            return closest_lane
        else:
            # The object is between center line of lanes
            a, b = closest_lane, second_closest_lane
            la, lb = abs(closest_lane_dist), abs(second_closest_lane_dist)
            return (b*la + a*lb)/(lb + la)

    def locate_objects_in_junction(self, tstates):
        tstates.dynamic_map.jmap.obstacles = []
        rospy.loginfo("surrounding objects number is %d",len(tstates.surrounding_object_list))
        if len(tstates.surrounding_object_list) > 0:
            s_obj = tstates.surrounding_object_list[0].state.pose.pose.position
            rospy.loginfo("surrounding object x: %f, y: %f",s_obj.x,s_obj.y)
        for obj in tstates.surrounding_object_list:
            if tstates.dynamic_map.model == MapState.MODEL_MULTILANE_MAP:
                obj.lane_index = self.locate_object_in_lane(obj.state, tstates)
            else:
                obj.lane_index = -1
            tstates.dynamic_map.jmap.obstacles.append(obj)

    # TODO: adjust lane_end_dist_thres to class variable
    def locate_ego_vehicle_in_lanes(self, tstates, lane_end_dist_thres=1.5, lane_dist_thres=5):
        dist_list = np.array([dist_from_point_to_polyline2d(
            tstates.ego_state.state.pose.pose.position.x, tstates.ego_state.state.pose.pose.position.y,
            lane, return_end_distance=True)
            for lane in tstates.static_map_lane_path_array])

        ego_lane_index = self.locate_object_in_lane(tstates.ego_state.state, tstates)
        ego_lane_index_rounded = int(round(ego_lane_index))

        rospy.loginfo("ego_lane_index=%d",ego_lane_index)

        self._ego_vehicle_distance_to_lane_head = dist_list[:, 3]
        self._ego_vehicle_distance_to_lane_tail = dist_list[:, 4]
        if ego_lane_index_rounded < 0 or self._ego_vehicle_distance_to_lane_tail[ego_lane_index_rounded] <= lane_end_dist_thres:
            # Drive into junction, wait until next map
            rospy.logdebug("In junction due to close to intersection, ego_lane_index = %f, dist_to_lane_tail = %f", ego_lane_index, self._ego_vehicle_distance_to_lane_tail[int(ego_lane_index)])
            tstates.dynamic_map.model = MapState.MODEL_JUNCTION_MAP
            # TODO: Calculate frenet coordinate here or in put_buffer?
            return
        else:
            tstates.dynamic_map.model = MapState.MODEL_MULTILANE_MAP
            tstates.dynamic_map.ego_ffstate = get_frenet_state(tstates.ego_state, 
                tstates.static_map_lane_path_array[ego_lane_index_rounded],
                tstates.static_map_lane_tangets[ego_lane_index_rounded])
            tstates.dynamic_map.mmap.ego_lane_index = ego_lane_index
            tstates.dynamic_map.mmap.distance_to_junction = self._ego_vehicle_distance_to_lane_tail[ego_lane_index_rounded]
        rospy.logdebug("Distance to end: (lane %f) %f", ego_lane_index, self._ego_vehicle_distance_to_lane_tail[ego_lane_index_rounded])

    def locate_surrounding_objects_in_lanes(self, tstates, lane_dist_thres=3):
        lane_front_vehicle_list = [[] for _ in tstates.static_map.lanes]
        lane_rear_vehicle_list = [[] for _ in tstates.static_map.lanes]

        # TODO: separate vehicle and other objects?
        if tstates.surrounding_object_list is not None:
            for vehicle_idx, vehicle in enumerate(tstates.surrounding_object_list):
                # rospy.loginfo("vehicle position: %f,%f",vehicle.state.pose.pose.position.x,vehicle.state.pose.pose.position.y)
                dist_list = np.array([dist_from_point_to_polyline2d(
                    vehicle.state.pose.pose.position.x,
                    vehicle.state.pose.pose.position.y,
                    lane, return_end_distance=True)
                    for lane in tstates.static_map_lane_path_array])
                # print("lane num: ",tstates.static_map_lane_path_array)
                closest_lane = np.argmin(np.abs(dist_list[:, 0]))
                # print(dist_list[:,0])
                rospy.loginfo("closest lane: %d", closest_lane)

                # Determine if the vehicle is close to lane enough
                if abs(dist_list[closest_lane, 0]) > lane_dist_thres:
                    continue 
                if dist_list[closest_lane, 3] < self._ego_vehicle_distance_to_lane_head[closest_lane]:
                    # The vehicle is behind if its distance to lane start is smaller
                    lane_rear_vehicle_list[closest_lane].append((vehicle_idx, dist_list[closest_lane, 3]))
                if dist_list[closest_lane, 4] < self._ego_vehicle_distance_to_lane_tail[closest_lane]:
                    # The vehicle is ahead if its distance to lane end is smaller
                    lane_front_vehicle_list[closest_lane].append((vehicle_idx, dist_list[closest_lane, 4]))
        
        # Put the vehicles onto lanes
        for lane_id in range(len(tstates.static_map.lanes)):
            front_vehicles = np.array(lane_front_vehicle_list[lane_id])
            rear_vehicles = np.array(lane_rear_vehicle_list[lane_id])

            if len(front_vehicles) > 0:
                # Descending sort front objects by distance to lane end
                for vehicle_row in reversed(front_vehicles[:,1].argsort()):
                    front_vehicle_idx = int(front_vehicles[vehicle_row, 0])
                    front_vehicle = tstates.surrounding_object_list[front_vehicle_idx]
                    front_vehicle.ffstate = get_frenet_state(front_vehicle.state,
                        tstates.static_map_lane_path_array[lane_id],
                        tstates.static_map_lane_tangets[lane_id]
                    )
                    # Here we use relative frenet coordinate
                    front_vehicle.ffstate.s = self._ego_vehicle_distance_to_lane_tail[lane_id] - front_vehicles[vehicle_row, 1]
                    front_vehicle.behavior = self.predict_vehicle_behavior(front_vehicle, tstates)
                    tstates.dynamic_map.mmap.lanes[lane_id].front_vehicles.append(front_vehicle)
                
                front_vehicle = tstates.dynamic_map.mmap.lanes[lane_id].front_vehicles[0]
                rospy.logdebug("Lane index: %d, Front vehicle id: %d, behavior: %d, x:%.1f, y:%.1f, d:%.1f", 
                                lane_id, front_vehicle.uid, front_vehicle.behavior,
                                front_vehicle.state.pose.pose.position.x,front_vehicle.state.pose.pose.position.y,
                                front_vehicle.ffstate.s)

            if len(rear_vehicles) > 0:
                # Descending sort rear objects by distance to lane end
                for vehicle_row in reversed(rear_vehicles[:,1].argsort()):
                    rear_vehicle_idx = int(rear_vehicles[vehicle_row, 0])
                    rear_vehicle = tstates.surrounding_object_list[rear_vehicle_idx]
                    rear_vehicle.ffstate = get_frenet_state(rear_vehicle.state,
                        tstates.static_map_lane_path_array[lane_id],
                        tstates.static_map_lane_tangets[lane_id]
                    )
                    # Here we use relative frenet coordinate
                    rear_vehicle.ffstate.s = rear_vehicles[vehicle_row, 1] - self._ego_vehicle_distance_to_lane_head[lane_id] # negative value
                    rear_vehicle.behavior = self.predict_vehicle_behavior(rear_vehicle, tstates)
                    tstates.dynamic_map.mmap.lanes[lane_id].rear_vehicles.append(rear_vehicle)
                
                rear_vehicle = tstates.dynamic_map.mmap.lanes[lane_id].rear_vehicles[0]
                rospy.logdebug("Lane index: %d, Rear vehicle id: %d, behavior: %d, x:%.1f, y:%.1f, d:%.1f", 
                                lane_id, rear_vehicle.uid, rear_vehicle.behavior, 
                                rear_vehicle.state.pose.pose.position.x,rear_vehicle.state.pose.pose.position.y,
                                rear_vehicle.ffstate.s)

    def locate_traffic_light_in_lanes(self, tstates):
        # TODO: Currently it's a very simple rule to locate the traffic lights
        if tstates.traffic_light_detection is None:
            return
        lights = tstates.traffic_light_detection.detections

        total_lane_num = len(tstates.static_map.lanes)
        if len(lights) == 1:
            for i in range(total_lane_num):
                if lights[0].signal == ObjectSignals.TRAFFIC_LIGHT_RED:
                    tstates.dynamic_map.mmap.lanes[i].map_lane.stop_state = Lane.STOP_STATE_STOP
                elif lights[0].signal == ObjectSignals.TRAFFIC_LIGHT_YELLOW:
                    tstates.dynamic_map.mmap.lanes[i].map_lane.stop_state = Lane.STOP_STATE_YIELD
                elif lights[0].signal == ObjectSignals.TRAFFIC_LIGHT_GREEN:
                    tstates.dynamic_map.mmap.lanes[i].map_lane.stop_state = Lane.STOP_STATE_THRU
        elif len(lights) > 1 and len(lights) == total_lane_num:
            for i in range(total_lane_num):
                if lights[i].signal == ObjectSignals.TRAFFIC_LIGHT_RED:
                    tstates.dynamic_map.mmap.lanes[i].map_lane.stop_state = Lane.STOP_STATE_STOP
                elif lights[i].signal == ObjectSignals.TRAFFIC_LIGHT_YELLOW:
                    tstates.dynamic_map.mmap.lanes[i].map_lane.stop_state = Lane.STOP_STATE_YIELD
                elif lights[i].signal == ObjectSignals.TRAFFIC_LIGHT_GREEN:
                    tstates.dynamic_map.mmap.lanes[i].map_lane.stop_state = Lane.STOP_STATE_THRU
        elif len(lights) > 1 and len(lights) != total_lane_num:
            red = True
            for i in range(len(lights)):
                if lights[i].signal == ObjectSignals.TRAFFIC_LIGHT_GREEN:
                    red = False
            for i in range(total_lane_num):
                if red:
                    tstates.dynamic_map.mmap.lanes[i].map_lane.stop_state = Lane.STOP_STATE_STOP
                else:
                    tstates.dynamic_map.mmap.lanes[i].map_lane.stop_state = Lane.STOP_STATE_THRU
        
    def locate_stop_sign_in_lanes(self, tstates):
        '''
        Put stop sign detections into lanes
        '''
        # TODO: Implement this
        pass

    def locate_speed_limit_in_lanes(self, tstates):
        '''
        Put stop sign detections into lanes
        '''
        # TODO(zhcao): Change the speed limit according to the map or the traffic sign(perception)
        # Now we set the multilane speed limit as 40 km/h.
        total_lane_num = len(tstates.static_map.lanes)
        for i in range(total_lane_num):
            tstates.dynamic_map.mmap.lanes[i].map_lane.speed_limit = 25

    # TODO(zyxin): Move this function into separate prediction module
    def predict_vehicle_behavior(self, vehicle, tstates, lane_change_thres = 0.2):
        '''
        Detect the behaviors of surrounding vehicles
        '''

        dist_list = np.array([dist_from_point_to_polyline2d(vehicle.state.pose.pose.position.x, vehicle.state.pose.pose.position.y, lane)
            for lane in tstates.static_map_lane_path_array])
        dist_list = np.abs(dist_list)
        closest_lane = dist_list[:, 0].argsort()[0]
        closest_idx = int(dist_list[closest_lane, 1])
        closest_point = tstates.dynamic_map.mmap.lanes[closest_lane].map_lane.central_path_points[closest_idx]

        vehicle_driving_direction = get_yaw(vehicle.state)
        lane_direction = closest_point.tangent
        d_theta = vehicle_driving_direction - lane_direction
        d_theta = wrap_angle(d_theta)

        # rospy.logdebug("id:%d, vehicle_direction:%.2f, lane_direction:%.2f",vehicle.uid,vehicle_driving_direction,lane_direction)
        if abs(d_theta) > lane_change_thres:
            if d_theta > 0:
                behavior = RoadObstacle.BEHAVIOR_MOVING_LEFT
            else:
                behavior = RoadObstacle.BEHAVIOR_MOVING_RIGHT
        else:
            behavior = RoadObstacle.BEHAVIOR_FOLLOW
        
        return behavior

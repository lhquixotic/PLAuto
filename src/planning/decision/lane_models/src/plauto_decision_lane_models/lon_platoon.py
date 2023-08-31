import numpy as np
import rospy
import time

from plauto_nav_msgs.msg import Lane
from plauto_nav_msgs.utils import get_speed, get_yaw
from plauto_cognition_msgs.msg import RoadObstacle
from plauto_nav_msgs.utils import get_lane_array, default_msg as navigation_default
from plauto_common.geometry import dist_from_point_to_polyline2d, wrap_angle


class PlatoonFSM(object):

    def __init__(self):
        
        self.dynamic_map = None # dynamic map:to obtain state
        self.platoon_state = None
         
        self.ego_lane_array = None # for locate ego vehicle in the ego lane
        
        self.platoon_lane_index = None
        self.leader_in_junction = None

    def update_dynamic_map(self,dynamic_map):
        self.dynamic_map = dynamic_map

    def update_platoon_state(self, platoon_state):
        self.platoon_state = platoon_state

    def longitudinal_speed(self, target_lane_index, traffic_light = False, if_record = False):
        platoon_veh, platoon_vehicle_lane = self.get_platoon_state()
        front_obstacle_vehicles = self.get_obstacle_state()
        # if no obstacle vehicle in the current lane, or the obstacle vehicle is in front of leader vehicle
        # target speed is the speed of the leader vehicle
        target_speed = platoon_veh.dynamics.lon_speed
        
        if len(front_obstacle_vehicles) == 0:
            rospy.loginfo("No obstacle vehicle in the current lane.")    
        else:
            closest_obstalce_loc = [front_obstacle_vehicles[0].state.pose.pose.position.x,
                                    front_obstacle_vehicles[0].state.pose.pose.position.y]
            closest_obstalce_loc = np.array(closest_obstalce_loc)
            rospy.logdebug("The closet obstacle location is %.2f,%.2f",closest_obstalce_loc[0],closest_obstalce_loc[1])
            # if obstacle vehicle is between the two vehicle, stop(FIXME)
            ego_veh_loc = np.array([self.dynamic_map.ego_state.pose.pose.position.x,
                                    self.dynamic_map.ego_state.pose.pose.position.y])
            pla_veh_loc = np.array([platoon_veh.odom.pose.pose.position.x,
                                    platoon_veh.odom.pose.pose.position.y])
            obstacle_leader_array = closest_obstalce_loc - pla_veh_loc
            obstacle_ego_array = closest_obstalce_loc - ego_veh_loc
            if np.dot(obstacle_leader_array,obstacle_ego_array) <= 0:
                # obstacle is between leader vehicle and ego vehicle            
                target_speed = 0
        return target_speed

    def get_platoon_state(self):
        rospy.logdebug("platoon vehicle num: %d",len(self.platoon_state.vehicles))
        platoon_veh = self.platoon_state.vehicles[0]
        
        # locate platoon vehicle in the lane
        lanes = [lane_state.map_lane for lane_state in self.dynamic_map.mmap.lanes]
        lane_path_array = get_lane_array(lanes)
        dist_list = np.array([dist_from_point_to_polyline2d(
            platoon_veh.odom.pose.pose.position.x,
            platoon_veh.odom.pose.pose.position.y,
            lane) for lane in lane_path_array])
        self.ego_lane_array = lane_path_array[int(self.dynamic_map.mmap.ego_lane_index)]

        if len(self.dynamic_map.mmap.lanes) < 2:
            closest_lane = second_closest_lane = 0
        else:
            closest_lane, second_closest_lane = np.abs(dist_list[:,0]).argsort()[:2]
        rospy.logdebug("The closest lane of the platoon vehicle is %d",closest_lane)
        return platoon_veh, closest_lane

    def get_obstacle_state(self):
        ego_vehicle_location = np.array([self.dynamic_map.ego_state.pose.pose.position.x,
                                        self.dynamic_map.ego_state.pose.pose.position.y])
        rospy.logdebug("number of lanes:%d",len(self.dynamic_map.mmap.lanes))
        ego_lane_index = self.dynamic_map.mmap.ego_lane_index
        rospy.logdebug("ego vehicle lane index is %d",ego_lane_index)
        ego_lane = self.dynamic_map.mmap.lanes[int(ego_lane_index)]
        front_vehicles = ego_lane.front_vehicles
        for vid,front_vehicle in enumerate(front_vehicles):
            vehicle_id = front_vehicle.uid
            rospy.logdebug("vehicle id is %d",vehicle_id)
            for platoon_veh in self.platoon_state.vehicles:
                platoon_veh_id = platoon_veh.uid
                rospy.logdebug("platoon vehicle id is %d", platoon_veh_id)
                if vehicle_id == platoon_veh_id:
                    rospy.logdebug("UID %d is platoon vehicle, delete.", vehicle_id)
                    del front_vehicles[vid]
                    
        if len(front_vehicles) > 0:
            rospy.logdebug("front vehicles num: %d",len(front_vehicles))
            return front_vehicles
        return []

    # TODO: more detailed FSM is to be added.

    def rule_state_transition(self,current_speed,ped_state):
        state = self.state
        PedinCrosswalk,dist,dist_y,ped_speed,ped_yaw = ped_state[0:5]
        dist_cmf = current_speed * current_speed/(2*self.a_cmf)
        dist_max = current_speed * current_speed/(2*self.a_max)
        
        if state == 1:
            if PedinCrosswalk and dist > 0:
                # enter transition
                if self.timeAdvantage(dist,dist_y,current_speed,ped_speed)>self.tau_max:
                    self.state = 1
                elif dist > dist_cmf:
                    self.state = 2
                elif dist > dist_max and dist < dist_cmf:
                    self.d_0 = dist
                    self.v_0 = current_speed
                    self.state = 3
                else:
                    self.state = 4
        elif not PedinCrosswalk: 
                self.state = 1

    def get_ped_state(self):
        dist = 100
        dist_y = 50
        ped_yaw = 90
        ped_speed = 0
        PedinCrosswalk = 0
        ego_vehicle_location = np.array([self.dynamic_map.ego_state.pose.pose.position.x,
                                        self.dynamic_map.ego_state.pose.pose.position.y])
        rospy.logdebug("number of lanes:%d",len(self.dynamic_map.mmap.lanes))
        
        #for lane in self.dynamic_map.mmap.lanes:
        for i in range(len(self.dynamic_map.mmap.lanes)):
            if self.dynamic_map.mmap.lanes[i] is not None:
                lane = self.dynamic_map.mmap.lanes[i]
                # obtain pedestrian's states in all lanes
                if len(lane.front_vehicles) > 0:
                    rospy.logdebug("Pedestrian detected")
                    ped = lane.front_vehicles[0]
                    ped_location = np.array([ped.state.pose.pose.position.x,
                                            ped.state.pose.pose.position.y])
                    dist = ego_vehicle_location[0] - ped_location[0] - self.veh_len/2 - self.delta
                    dist_y = ego_vehicle_location[1] - ped_location[1] - self.veh_wid/2
                    ped_yaw = get_yaw(ped.state)
                    ped_speed = get_speed(ped.state)
                    PedinCrosswalk = 1
        return PedinCrosswalk,dist,dist_y,ped_speed,ped_yaw
    
    def lon_action(self,state,current_speed,ped_state):
        limit_speed = self.limit_speed
        dist = ped_state[1]
        dist_cmf = current_speed * current_speed/(2*self.a_cmf)
        dist_max = current_speed * current_speed/(2*self.a_max) 

        if state == 1:
            target_acc = min(self.k_s * (current_speed - limit_speed), self.a_max)
        elif state == 2:
            if dist > dist_cmf + current_speed * self.delay_time:
                self.setup = 0
                desired_acc = 0
                desired_speed = self.limit_speed
            else:
                if self.setup == 0:
                    self.d_0 = dist
                    self.v_0 = current_speed
                    self.setup = 1
                desired_acc = - self.a_cmf
                desired_speed = self.getDesiredSpeed(dist)
            target_acc = desired_acc + self.k_s * (current_speed - desired_speed)
        elif state == 3:
            desired_speed = self.getDesiredSpeed(dist)
            target_acc = -current_speed * current_speed/(2*dist) + self.k_s*(current_speed - desired_speed)
        elif state == 4:
            target_acc = self.a_cmf
        # Calculate target speed 
        target_speed = current_speed + target_acc * self.decision_dt
        return target_speed
    
    def timeAdvantage(self,dist,dist_y,veh_speed,ped_speed):
        if veh_speed == 0:
            time_advantage = self.tau_max + 1
        elif ped_speed == 0:
            time_advantage = self.tau_max - 1
        else:
            time_advantage = dist_y/ped_speed - dist/veh_speed
        rospy.logdebug("time_advantage=%.3f",time_advantage)
        return time_advantage

    def getDesiredSpeed(self,dist):
        if self.state == 2: # Yielding
            v_des = (max(2*self.a_cmf*(dist - self.d_0) + self.v_0 * self.v_0,0))**0.5
        elif self.state == 3: # Hard Braking
            v_des = self.v_0 * (max(dist/self.d_0,0)) ** 0.5
        rospy.logdebug('desired speed is: %.3f',v_des)
        return v_des
    
import math
import tf.transformations as tft

from plauto_nav_msgs.msg import RigidBodyState, RigidBodyStateStamped
from geometry_msgs.msg import Pose, PoseWithCovariance, Twist, TwistWithCovariance

import numpy as np
from plauto_nav_msgs.msg import Map

def get_speed(msg):
    '''
    Calculate speed value
    '''
    if type(msg) == Twist:
        return math.sqrt(msg.linear.x**2 + msg.linear.y**2 + msg.linear.z**2)
    elif type(msg) == TwistWithCovariance or type(msg) == RigidBodyState:
        return get_speed(msg.twist)
    elif type(msg) == RigidBodyStateStamped:
        return get_speed(msg.state)
    else:
        raise ValueError("Incorrect message type for get_speed")

def get_yaw(msg):
    '''
    Calculate yaw angle assuming on 2d plane
    '''
    if type(msg) == Pose:
        _,_,yaw = tft.euler_from_quaternion([msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w])
        return yaw
    elif type(msg) == PoseWithCovariance or type(msg) == RigidBodyState:
        return get_yaw(msg.pose)
    elif type(msg) == RigidBodyStateStamped:
        return get_yaw(msg.state)
    else:
        raise ValueError("Incorrect message type for get_yaw")

def get_position(msg):
    '''
    Calculate location x,y
    '''
    if type(msg) == Pose:
        x = msg.position.x
        y = msg.position.y
        return x,y
    elif type(msg) == PoseWithCovariance or type(msg) == RigidBodyState:
        return get_position(msg.pose)
    elif type(msg) == RigidBodyStateStamped:
        return get_position(msg.state)
    else:
        raise ValueError("Incorrect message type for get_position")

def convert_odometry_to_state(msg):
    '''
    Convert nav_msgs/Odometry to zzz_driver_msgs/RigidBodyStateStamped
    '''

    new_msg = RigidBodyStateStamped()
    new_msg.header = msg.header
    new_msg.state.child_frame_id = msg.child_frame_id

    new_msg.state.pose = msg.pose
    new_msg.state.twist = msg.twist
    return new_msg

def default_msg(msg_type):
    '''
    Setting default values for the messages
    '''
    if msg_type == Map:
        msg = Map()
        msg.in_junction = True
    else:
        raise ValueError("Unrecognized message type")
    
    return msg

def get_lane_array(lanes):
    arrays = []
    for lane in lanes:
        point_list = [(point.position.x, point.position.y) for point in lane.central_path_points]
        arrays.append(np.array(point_list))
    return arrays

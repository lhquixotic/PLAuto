import rospy
import numpy as np
import math
# from cvxopt import solvers, matrix
from plauto_common.geometry import dense_polyline2d, dist_from_point_to_polyline2d
from plauto_cognition_msgs.msg import MapState
from plauto_nav_msgs.utils import get_speed, get_yaw

class ReconstructedTrajectory(object):
    def __init__(self):
        self.recons_traj = None
    
    def update_reconstructed_trajectory(self,recons_traj):
        self.recons_traj = recons_traj
        
    def get_trajectory(self):
        trajectory = self.recons_traj
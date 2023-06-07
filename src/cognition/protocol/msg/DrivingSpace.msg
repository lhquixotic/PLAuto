# This message represents a homogeneous representation of driving space (static and dynamic map)

Header header

# Ego Vehicle Info
plauto_nav_msgs/RigidBodyState ego_state

float32 ego_lane_index

# Static Info
plauto_nav_msgs/Lane[] lanes

# Dynamic Info
RoadObstacle[] obstacles

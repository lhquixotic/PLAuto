Header header
int32 increment
int32 lane_id
Waypoint[] waypoints

uint32 lane_index
float32 cost
float32 closest_object_distance
float32 closest_object_velocity
bool is_blocked

# ----- Central path representation -----
# The central_path_points field is used when central_path_type is waypoint.
# Otherwise, central_path_coeffs should be used
LanePoint[] central_path_points
float32[] central_path_coeffs
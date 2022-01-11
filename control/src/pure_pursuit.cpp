#include "pure_pursuit.hpp"

Pure_pursuit::Pure_pursuit(const double wheelbase){
    wheel_base = wheelbase;
}

double Pure_pursuit::outputSteeringWheelAngle(geometry_msgs::Point target,
        geometry_msgs::Pose current_pose){
    double kappa;
    double d = getPlaneDistance(target,current_pose.position);
    double denominator = d * d;
    double rel_x = calcRelativeCoordinate(target, current_pose).x;
    double rel_y = calcRelativeCoordinate(target, current_pose).y;
    double numerator = 2 * rel_y;
    ROS_INFO("relative coordinate x: %f, y: %f.",rel_x,rel_y);
    
    if(denominator != 0){
        kappa = numerator / denominator;
    }else{
        if (numerator > 0){
            kappa = KAPPA_MIN;
        }else{
            kappa = KAPPA_MAX;
        }
    }
    double target_steering_angle = atan(wheel_base * kappa) * 180 / M_PI;
    // limit front wheel angel
    BOUND(target_steering_angle,LIMIT_STEERING_ANGLE,-LIMIT_STEERING_ANGLE);

    return target_steering_angle;
}

// double Pure_pursuit::outputSteeringWheelAngle(autoware_msgs::Waypoint reference_waypoint){
//     double target_front_wheel_angle = outputFrontWheelAngle(reference_waypoint);
//     double target_steering_wheel_angle = 24 * target_front_wheel_angle + 4.8; // deg 
//     //mapping between front angle to steering wheel angle

//     return target_steering_wheel_angle;
// }

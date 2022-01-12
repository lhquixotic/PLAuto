#include "pid.hpp"
#include "ros/ros.h"

PID::PID(const double p, const double i, const double d) {
    kp = p;
    ki = i;
    kd = d;
    target = 0;
    actual = 0;
    error_pre = 0;
}

double PID::outputSignal(double tar, double act) {
    double u;
    target = tar;
    actual = act;
    error = actual - target;
    integral += error;
    if(integral > PID_INT_MAX){
        integral = PID_INT_MAX;
    }else{
        if (integral < -PID_INT_MAX){
            integral = -PID_INT_MAX;
        }
    }
    ROS_INFO_STREAM("[PID control]" << "target: " << tar << ", act: " << act << ", integral: " << integral);
    u = kp * error + ki * integral + kd * (error - error_pre);
    ROS_INFO_STREAM("[PID control]" << "u: " << u);
    error_pre = error;
    return u;
}

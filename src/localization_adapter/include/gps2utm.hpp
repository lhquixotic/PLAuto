#pragma once

#include "common_msgs/GpsInfo.h"
#include <string>
#include <cmath>
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Quaternion.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf/transform_datatypes.h"
namespace utm{
struct Gps_point{
    double x; // lon
    double y; // lat
    double z; // alt
};
struct Gps_para{
    double lat_min;
    double lat_max;
    double lon_min;
    double lon_max;
};

// WGS84 coordinate system parameters
const double WGS84_A = 6378137.0;		// major axis
const double WGS84_B = 6356752.31424518;	// minor axis
const double WGS84_F = 0.0033528107;		// ellipsoid flattening
const double WGS84_E = 0.0818191908;		// first eccentricity
const double WGS84_EP = 0.0820944379;		// second eccentricity

// UTM Parameters
const double UTM_K0 = 0.9996;			// scale factor
const double UTM_FE = 500000.0;		// false easting
const double UTM_FN_N = 0.0;			// false northing on north hemisphere
const double UTM_FN_S = 10000000.0;		// false northing on south hemisphere
const double UTM_E2 = (WGS84_E * WGS84_E);	// e^2
const double UTM_E4 = (UTM_E2 * UTM_E2);		// e^4
const double UTM_E6 = (UTM_E4 * UTM_E2);		// e^6
const double UTM_EP2 = (UTM_E2 / (1 - UTM_E2));	// e'^2

nav_msgs::Odometry gps2odom(common_msgs::GpsInfo gps_info);
geometry_msgs::Point lla2utm(sensor_msgs::NavSatFix fix);

char latitude_zone_letter(const double &lat);
int longitude_zone_number(const double &lat, const double &lon);
double deg2rad(double deg);
geometry_msgs::Quaternion rpy2qtn(geometry_msgs::Vector3 rpy);

}

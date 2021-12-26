#ifndef GPSCONVERT
#define GPSCONVERT

#include <cmath>
#include <cstring>
#include <string>

namespace gps {

const double PI = atan(1.0) * 4;

double haversin(double theta) ;
double D2R(double theta);
double SphereDis(double lon1, double lat1, double lon2, double lat2) ;
double mod(double x, double y) ;
double SphereAzimuth(double lon1, double lat1, double lon2, double lat2) ;
void CalNewLatLon(double lat1,double lon1,double dis,double azi,double &retlat2,double &retlon2);
}  // namespace gps

#endif
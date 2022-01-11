#pragma once

#include <cstring>
#include <string>
#include <cmath>

using namespace std;
const double PI=atan(1.0)*4;

struct Gps_point{
    double E; // lon
    double N; // lat
};

double haversin(double theta);
double D2R(double theta);
double SphereDis(double lon1,double lat1,double lon2,double lat2);
double mod(double x,double y);
double SphereAzimuth(double lon1,double lat1,double lon2,double lat2);
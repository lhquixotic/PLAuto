#include "gps_convert.h"

namespace gps {


double haversin(double theta) {
  return sin(theta / 2) * sin(theta / 2);
}
double D2R(double theta) { return theta * PI / 180.0; }
double R2D(double theta) { return theta / PI * 180.0; }
double SphereDis(double lon1, double lat1, double lon2, double lat2) {
  // return  from p1 to p2 distance  unit:m
  double R = 6378.137 * 1000;
  double x1 = D2R(lon1), x2 = D2R(lat1);
  double y1 = D2R(lon2), y2 = D2R(lat2);
  double h = haversin(abs(x2 - y2)) +
             cos(x2) * cos(y2) * haversin(abs(x1 - y1));
  double d = 2 * R * asin(sqrt(h));
  return d;
}
double mod(double x, double y) {
  if (fmod(x, y) < 0) {
    return fmod(x, y) + y;
  } else
    return fmod(x, y);
}
double SphereAzimuth(double lon1, double lat1, double lon2, double lat2) {
  // return  from p1 to p2 azimuth  unit:rad
  double x1 = D2R(lon1), x2 = D2R(lat1);
  double y1 = D2R(lon2), y2 = D2R(lat2);
  double tc1 =
      mod(atan2(sin(y1 - x1) * cos(y2),
                     cos(x2) * sin(y2) -
                         sin(x2) * cos(y2) * cos(y1 - x1)),
          2 * PI);
  return tc1;
}
void CalNewLatLon(double lat1,double lon1,double dis,double azi,double &retlat2,double &retlon2){
  //lat,lon,azi unit:degree,  dis unit:m
  //lat1,lon1: position of point1; dis: distance from point2 to point1.  azi: point1 as original point, north as 0,east as 90
  double R = 6378.137 * 1000;
  double c=dis/R;
  double azi1=D2R(azi);
  double x1=D2R(lon1),y1=D2R(lat1);
  double a=acos(cos(0.5*PI-y1)*cos(c)+sin(0.5*PI-y1)*sin(c)*cos(azi1));
  double C=asin(sin(c)*sin(azi1)/sin(a));
  double y2=R2D(0.5*PI-a);
  double x2=R2D(x1+C);
  retlat2=y2;
  retlon2=x2;

}
}  // namespace gps
//http://blog.sina.com.cn/s/blog_658a93570101hynw.html
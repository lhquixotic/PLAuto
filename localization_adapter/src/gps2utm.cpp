#include "gps2utm.hpp"

namespace utm{

nav_msgs::Odometry gps2odom(common_msgs::GpsInfo gps_info){
    nav_msgs::Odometry utm;
    utm.header = gps_info.header;
    utm.pose.pose.position = lla2utm(gps_info.fix);
    utm.pose.pose.orientation = rpy2qtn(gps_info.rpy);
    utm.twist.twist = gps_info.twist;
    return utm;
}

geometry_msgs::Point lla2utm(sensor_msgs::NavSatFix fix){

    double lat = fix.latitude;
    double lon = fix.longitude;
    double easting;
    double northing;

	double a = WGS84_A;
	double eccSquared = UTM_E2;
	double k0 = UTM_K0;

	double LongOrigin;
	double eccPrimeSquared;
	double N, T, C, A, M;

	double LatRad = deg2rad(lat);
	double LongRad = deg2rad(lon);
	double LongOriginRad;

    LongOrigin = (longitude_zone_number(lat,lon) - 1)*6 - 180 + 3;
	LongOriginRad = deg2rad(LongOrigin);

    eccPrimeSquared = (eccSquared)/(1-eccSquared);

	N = a/sqrt(1-eccSquared*sin(LatRad)*sin(LatRad));
	T = tan(LatRad)*tan(LatRad);
	C = eccPrimeSquared*cos(LatRad)*cos(LatRad);
	A = cos(LatRad)*(LongRad-LongOriginRad);

	M = a*((1	- eccSquared/4		- 3*eccSquared*eccSquared/64	- 5*eccSquared*eccSquared*eccSquared/256)*LatRad
				- (3*eccSquared/8	+ 3*eccSquared*eccSquared/32	+ 45*eccSquared*eccSquared*eccSquared/1024)*sin(2*LatRad)
									+ (15*eccSquared*eccSquared/256 + 45*eccSquared*eccSquared*eccSquared/1024)*sin(4*LatRad)
									- (35*eccSquared*eccSquared*eccSquared/3072)*sin(6*LatRad));

	easting = (double)(k0*N*(A+(1-T+C)*A*A*A/6
					+ (5-18*T+T*T+72*C-58*eccPrimeSquared)*A*A*A*A*A/120)
					+ 500000.0);

	northing = (double)(k0*(M+N*tan(LatRad)*(A*A/2+(5-T+9*C+4*C*C)*A*A*A*A/24
				 + (61-58*T+T*T+600*C-330*eccPrimeSquared)*A*A*A*A*A*A/720)));
	if(lat < 0)
		northing += 10000000.0; //10000000 meter offset for southern hemisphere

    // Point format
    geometry_msgs::Point position;
    position.x = easting;
    position.y = northing;
    position.z = fix.altitude;

    return position;
}

geometry_msgs::Quaternion rpy2qtn(geometry_msgs::Vector3 rpy){
    tf2::Quaternion qtn;
    //qtn.setRPY(rpy.x,rpy.y,rpy.z);
    qtn.setRPY(deg2rad(rpy.x),deg2rad(rpy.y),deg2rad(rpy.z));
    geometry_msgs::Quaternion qtn_;
    qtn_.w = qtn.getW();
    qtn_.x = qtn.getX();
    qtn_.y = qtn.getY();
    qtn_.z = qtn.getZ();
    return qtn_;
}

char latitude_zone_letter(const double &lat){
    char LetterDesignator;

	if ((84 >= lat) && (lat >= 72))  LetterDesignator = 'X';
	else if ((72 > lat) && (lat >= 64))  LetterDesignator = 'W';
	else if ((64 > lat) && (lat >= 56))  LetterDesignator = 'V';
	else if ((56 > lat) && (lat >= 48))  LetterDesignator = 'U';
	else if ((48 > lat) && (lat >= 40))  LetterDesignator = 'T';
	else if ((40 > lat) && (lat >= 32))  LetterDesignator = 'S';
	else if ((32 > lat) && (lat >= 24))  LetterDesignator = 'R';
	else if ((24 > lat) && (lat >= 16))  LetterDesignator = 'Q';
	else if ((16 > lat) && (lat >= 8))   LetterDesignator = 'P';
	else if ((8 > lat) && (lat >= 0))   LetterDesignator = 'N';
	else if ((0 > lat) && (lat >= -8))  LetterDesignator = 'M';
	else if ((-8 > lat) && (lat >= -16)) LetterDesignator = 'L';
	else if ((-16 > lat) && (lat >= -24)) LetterDesignator = 'K';
	else if ((-24 > lat) && (lat >= -32)) LetterDesignator = 'J';
	else if ((-32 > lat) && (lat >= -40)) LetterDesignator = 'H';
	else if ((-40 > lat) && (lat >= -48)) LetterDesignator = 'G';
	else if ((-48 > lat) && (lat >= -56)) LetterDesignator = 'F';
	else if ((-56 > lat) && (lat >= -64)) LetterDesignator = 'E';
	else if ((-64 > lat) && (lat >= -72)) LetterDesignator = 'D';
	else if ((-72 > lat) && (lat >= -80)) LetterDesignator = 'C';
	// 'Z' is an error flag, the Latitude is outside the UTM limits
	else LetterDesignator = 'Z';
	return LetterDesignator;
}

int longitude_zone_number(const double &lat,const double &lon){
	int ZoneNumber;

	ZoneNumber = int((lon + 180) / 6) + 1;

	if (lat >= 56.0 && lat < 64.0 && lon >= 3.0 && lon < 12.0)
		ZoneNumber = 32;

	// Special zones for Svalbard
	if (lat >= 72.0 && lat < 84.0)
	{
		if (lon >= 0.0 && lon < 9.0) ZoneNumber = 31;
		else if (lon >= 9.0 && lon < 21.0) ZoneNumber = 33;
		else if (lon >= 21.0 && lon < 33.0) ZoneNumber = 35;
		else if (lon >= 33.0 && lon < 42.0) ZoneNumber = 37;
	}
	return ZoneNumber;
}

double deg2rad(double deg){
    return deg * M_PI/180.0;
}

}

# Adapted from CLAP (https://github.com/CLAP-Framework/clap)
Header header

# Level of accelaration, unit in m/s^2, throttle is positive, braking is negative
# [-1.0, 1.0]
float32 accel

# Level of steering on front wheel, unit in radian, left turning is positive
# [-1.0,1.0]
float32 steer

# Gear shift, positive means manual transmission, negative means automatic transmission
int8 gear
int8 GEAR_NONE = 0
int8 GEAR_NEUTRAL = -1
int8 GEAR_REVERSE = -2
int8 GEAR_PARKING = -3
int8 GEAR_DRIVE = -4

# Parking brake switch
bool parking_brake
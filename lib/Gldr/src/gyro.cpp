#include "gyro.h"
#include <Arduino.h>


namespace gldr
{
    Gyro::Gyro(int min_accel, int max_accel)
        : _min_accel(min_accel),
        _max_accel(max_accel),
        _rotX(0),
        _rotY(0),
        _rotZ(0)
    {}


    double Gyro::getX()
    {
        return RAD_TO_DEG * atan2(-_rotY, -_rotZ) + PI;
    }


    double Gyro::getY()
    {
        return RAD_TO_DEG * atan2(-_rotX, -_rotZ) + PI;
    }


    double Gyro::getZ()
    {
        return RAD_TO_DEG * atan2(-_rotY, -_rotX) + PI;
    }
}

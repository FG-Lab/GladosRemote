#include <Arduino.h>
#include "joystick.h"


namespace gldr
{

    Joystick::Joystick(int min, int max)
    {
        _min = min;
        _max = max;
        _y_axis = max/2;
        _x_axis = max/2;
    }

    double Joystick::getX()
    {
        return ((double)map(_x_axis, _min, _max, -1000, 1000)) / 1000;
    }

    double Joystick::getY()
    {
        return ((double)map(_y_axis, _min, _max, -1000, 1000)) / 1000;
    }

    bool Joystick::getSwitch()
    {
        return _switch;
    }
}

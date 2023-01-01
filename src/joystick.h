#pragma once


#include "inttypes.h"


namespace gldr
{
    class Joystick
    {
    public:
        /**
         * Constructs a new Joystick object.
         *
         * @param min The sticks minimum value
         * @param max The sticks maximum value
         */
         Joystick(int min, int max);

        /**
         * Retrieve the sticks tilt along the X axis.
         *
         * @return Normalized value between -1.0 and 1.0 where 0.0 is the center position.
         */
        double getX();

        /**
         * Retrieve the sticks tilt along the Y axis.
         *
         * @return Normalized value between -1.0 and 1.0 where 0.0 is the center position.
         */
        double getY();

        /**
         * Retrieve the the state of the sticks button also called switch.
         *
         * @return True if pressed otherwise false.
         */
        bool getSwitch();

    private:
        int _min;
        int _max;

    protected:
        uint16_t _y_axis;
        uint16_t _x_axis;
        bool    _switch;
    };
}

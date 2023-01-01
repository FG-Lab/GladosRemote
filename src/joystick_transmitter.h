#pragma once


#include "joystick.h"
#include "serializable.h"


namespace gldr
{
    class JoystickTransmitter : public Joystick, public Serializeable
    {
    public:
        /**
         * Constructs a new Joystick object. The Hardware counter part should be connected to the
         * pins indicated by this constructors parameters.
         *
         * @param switch_pin    Digital pin which is used to check whether the sticks button was pressed.
         * @param x_analog_pin  Analog pin which is used to retrieve the sticks tilt along the X axis.
         * @param y_analog_pin  Analog pin which is used to retrieve the sticks tilt along the Y axis.
         * @param min The sticks minimum value
         * @param max The sticks maximum value
         */
        JoystickTransmitter(int switch_pin, int x_analog_pin, int y_analog_pin, int min=0, int max=1024);

        /**
         *  Updates this object to reflect the current state of the Joystick.
         */
        void update();
        uint8_t* serialize(int& length_buffer) override;

    private:
        // Pins
        int _switch_pin;
        int _x_analog;
        int _y_analog;


    };
}

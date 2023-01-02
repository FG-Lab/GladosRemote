#include "joystick_transmitter.h"
#include <Arduino.h>

namespace gldr
{
    JoystickTransmitter::JoystickTransmitter(int switch_pin, int x_analog_pin, int y_analog_pin, int min, int max) : Joystick(min, max)
    {
        _switch_pin = switch_pin;
        _x_analog = x_analog_pin;
        _y_analog = y_analog_pin;

        pinMode(_switch_pin, INPUT_PULLUP);
    }

    void JoystickTransmitter::update()
    {
        _switch = digitalRead(_switch_pin) != HIGH;
        _x_axis = analogRead(_x_analog);
        _y_axis = analogRead(_y_analog);
    }

    uint8_t* JoystickTransmitter::serialize(int& length_buffer)
    {
        length_buffer = 5;
        static uint8_t buffer[5];

        // X-Axis
        buffer[0] = (uint8_t)(_x_axis >> 8);
        buffer[1] = _x_axis;

        // Y-Axis
        buffer[2] = (uint8_t)(_y_axis >> 8);
        buffer[3] = _y_axis;

        // switch
        buffer[4] = (bool)_switch;

        return buffer;
    }
}

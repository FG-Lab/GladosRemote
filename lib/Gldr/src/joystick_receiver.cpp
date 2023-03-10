#include "joystick_receiver.h"
#include "Arduino.h"


namespace gldr
{
    JoystickReceiver::JoystickReceiver(int min, int max) : Joystick(min, max) {}

    void JoystickReceiver::deserialize(uint8_t *data, int index)
    {
        _x_axis = 0;
        _y_axis = 0;
        _switch = false;

        _x_axis = (((uint16_t)data[index])   << 8) | data[index+1];
        _y_axis = (((uint16_t)data[index+2]) << 8) | data[index+3];
        _switch = data[index+4];
    }
}


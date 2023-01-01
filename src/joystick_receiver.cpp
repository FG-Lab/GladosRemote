#include "joystick_receiver.h"
#include "Arduino.h"


namespace gldr
{
    JoystickReceiver::JoystickReceiver(int min, int max) : Joystick(min, max) {}

    void JoystickReceiver::deserialize(uint8_t *data, int index)
    {
        _x_axis = (data[index]   << 8) | data[index+1];
        _y_axis = (data[index+2] << 8) | data[index+3];
        _switch = (bool)data[index+4];
    }
}


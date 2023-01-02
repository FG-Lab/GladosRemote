#include "remote_receiver.h"


namespace gldr
{
    RemoteReceiver::RemoteReceiver(int rx, int tx, JoystickReceiver& joystick, long baud)
        : Remote(rx, tx, baud),
          _joystick(joystick)
    {}

    void RemoteReceiver::update()
    {
        static const int buffer_length = 5;

        if (_serial_interface->available())
        {
            uint8_t  buffer[buffer_length];
            _serial_interface->readBytes(buffer, buffer_length);
            _joystick.deserialize(buffer, 0);
        }
    }

    double RemoteReceiver::joystick_x()
    {
        return _joystick.getX();
    }

    double RemoteReceiver::joystick_y()
    {
        return _joystick.getY();
    }

    bool RemoteReceiver::joystick_switch()
    {
        return _joystick.getSwitch();
    }
}

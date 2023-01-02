#include "remote_receiver.h"


namespace gldr
{
    RemoteReceiver::RemoteReceiver(int rx, int tx, JoystickReceiver& joystick, GyroReceiver& gyro, long baud)
        : Remote(rx, tx, baud),
          _joystick(joystick),
          _gyro(gyro)
    {}

    void RemoteReceiver::update()
    {

        if (_serial_interface->available())
        {
            _serial_interface->readBytes(_buffer, buffer_length);
            _joystick.deserialize(_buffer, 1);
            _gyro.deserialize(_buffer, 6);
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

    double RemoteReceiver::gyro_x()
    {
        return _gyro.getX();
    }

    double RemoteReceiver::gyro_y()
    {
        return _gyro.getY();
    }

    double RemoteReceiver::gyro_z()
    {
        return _gyro.getZ();
    }
}

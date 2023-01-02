#pragma once


#include "remote.h"
#include "joystick_receiver.h"
#include "gyro_receiver.h"

namespace gldr
{
    class RemoteReceiver : public Remote
    {
    public:
        RemoteReceiver(int rx, int tx, JoystickReceiver& joystick, GyroReceiver& gyro, long baud=9600);
        void update();

        double joystick_x();
        double joystick_y();
        bool joystick_switch();

        double gyro_x();
        double gyro_y();
        double gyro_z();


    private:
        JoystickReceiver& _joystick;
        GyroReceiver& _gyro;

        static const int buffer_length = 12;
        uint8_t  _buffer[buffer_length];
    };
}

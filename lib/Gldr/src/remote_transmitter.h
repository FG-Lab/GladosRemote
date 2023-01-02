#pragma once


#include "remote.h"
#include "joystick_transmitter.h"
#include "gyro_transmitter.h"


namespace gldr
{
    class RemoteTransmitter : public Remote
    {
    public:
        RemoteTransmitter(int rx, int tx,
                          JoystickTransmitter& joystick,
                          GyroTransmitter& gyro,
                          int interval=50, long baud=9600);
        void update();
        void transmit();

    private:
        unsigned int _interval;
        unsigned long _elapsed;
        JoystickTransmitter& _joystick;
        GyroTransmitter& _gyro;
    };
}

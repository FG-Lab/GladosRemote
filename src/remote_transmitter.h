#pragma once


#include "remote.h"
#include "joystick_transmitter.h"


namespace gldr
{
    class RemoteTransmitter : public Remote
    {
    public:
        RemoteTransmitter(int rx, int tx, JoystickTransmitter& joystick, long baud=9600);
        void transmit();

    private:
        JoystickTransmitter& _joystick;
    };
}

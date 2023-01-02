#pragma once


#include "remote.h"
#include "joystick_receiver.h"


namespace gldr
{
    class RemoteReceiver : public Remote
    {
    public:
        RemoteReceiver(int rx, int tx, JoystickReceiver& joystick, long baud=9600);
        void update();

        double joystick_x();
        double joystick_y();
        bool joystick_switch();


    private:
        JoystickReceiver& _joystick;
    };
}

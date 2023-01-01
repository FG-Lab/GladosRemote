#pragma once


#include "remote.h"
#include "deserializable.h"
#include "joystick_receiver.h"


namespace gldr
{
    class RemoteReceiver : public Remote
    {
    public:
        RemoteReceiver(int rx, int tx, JoystickReceiver& joystick, long baud=9600);
        void update();
        void request();


    private:
        bool _ongoing_request;
        JoystickReceiver& _joystick;
    };
}

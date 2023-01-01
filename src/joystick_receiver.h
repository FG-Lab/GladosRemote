#pragma once


#include "joystick.h"
#include "deserializable.h"


namespace gldr
{
    class JoystickReceiver : public Joystick, public Deserializeable
    {
    public:
        explicit JoystickReceiver(int min=0, int max=1024);
        void deserialize(uint8_t* data, int index) override;
    };
}


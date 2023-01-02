#pragma once

#include "gyro.h"
#include "deserializable.h"


namespace gldr
{
    class GyroReceiver : public Gyro, public Deserializeable
    {
    public:
        GyroReceiver();
        void deserialize(uint8_t* data, int index) override;
    };
}


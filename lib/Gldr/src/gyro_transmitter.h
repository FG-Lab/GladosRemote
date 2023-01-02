#pragma once

#include "gyro.h"
#include "serializable.h"

#define GYRO_ADDRESS 0x68


namespace gldr
{
    class GyroTransmitter : public Gyro, public Serializeable
    {
    public:
        GyroTransmitter(int min_accel=265, int max_accel=402);
        void update();
        void setup();
        uint8_t* serialize(int& length_buffer) override;
    };
}

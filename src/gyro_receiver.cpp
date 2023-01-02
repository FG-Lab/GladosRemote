#include "gyro_receiver.h"


namespace gldr
{
    GyroReceiver::GyroReceiver() : Gyro(0, 0) {}

    void GyroReceiver::deserialize(uint8_t *data, int index)
    {
        _rotX = (data[index]   << 8) | data[index+1];
        _rotY = (data[index+2] << 8) | data[index+3];
        _rotZ = (data[index+4] << 8) | data[index+5];
    }
}


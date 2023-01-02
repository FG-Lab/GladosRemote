#include "gyro_transmitter.h"
#include <Wire.h>
#include <Arduino.h>


namespace gldr
{
    GyroTransmitter::GyroTransmitter(int min_accel, int max_accel) : Gyro(min_accel, max_accel)
    {}


    void GyroTransmitter::update()
    {
        Wire.beginTransmission(GYRO_ADDRESS);
        Wire.write(0x3B);
        Wire.endTransmission(false);

        Wire.requestFrom(GYRO_ADDRESS, 6, true);

        _rotX = (Wire.read() << 8 | Wire.read());
        _rotY = (Wire.read() << 8 | Wire.read());
        _rotZ = (Wire.read() << 8 | Wire.read());

        _rotX = (int) map(_rotX, _min_accel, _max_accel, -90, 90);
        _rotY = (int) map(_rotY, _min_accel, _max_accel, -90, 90);
        _rotZ = (int) map(_rotZ, _min_accel, _max_accel, -90, 90);
    }

    void GyroTransmitter::setup()
    {
        Wire.begin();
        Wire.beginTransmission(GYRO_ADDRESS);

        // Disable Gyro sleep mode
        Wire.write(0x6B);
        Wire.write(0);

        // Send data queued by Wire.write()
        Wire.endTransmission(true);
    }

    uint8_t* GyroTransmitter::serialize(int& length_buffer)
    {
        length_buffer = 6;
        static uint8_t buffer[6];

        buffer[0] = (_rotX >> 8);
        buffer[1] = _rotX;

        buffer[2] = (_rotY >> 8);
        buffer[3] = _rotY;

        buffer[4] = (_rotZ >> 8);
        buffer[5] = _rotZ;

        return buffer;
    }
}

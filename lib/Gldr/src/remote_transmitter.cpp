#include "remote_transmitter.h"


namespace gldr
{
    RemoteTransmitter::RemoteTransmitter(int rx, int tx,
                                         JoystickTransmitter& joystickTransmitter,
                                         GyroTransmitter& gyro,
                                         int interval, long baud)
        : Remote(rx, tx, baud),
          _interval(interval),
          _elapsed(0),
          _joystick(joystickTransmitter),
          _gyro(gyro)
    {}

    void RemoteTransmitter::update()
    {
        _joystick.update();
        _gyro.update();
    }

    void RemoteTransmitter::transmit()
    {
        if (millis() - _elapsed < _interval) return;
        _elapsed = millis();

        update();

        int len_joystick;

        int data_index = 0;
        int complete_length = 0;

        uint8_t* joystick_data = _joystick.serialize(len_joystick);
        complete_length += len_joystick;

        uint8_t data[complete_length];

        for (int i=0; i<len_joystick; i++) data[i + data_index] = joystick_data[i];
        data_index += len_joystick;

        _serial_interface->write(data, complete_length);
    }
}

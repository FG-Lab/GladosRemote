#include "remote_receiver.h"


namespace gldr
{
    RemoteReceiver::RemoteReceiver(int rx, int tx, JoystickReceiver& joystick, long baud)
        : Remote(rx, tx, baud),
          _ongoing_request(false),
          _joystick(joystick)
    {}

    void RemoteReceiver::request()
    {
        if (_ongoing_request) return;

        _ongoing_request = true;
        _serial_interface->write(125);
    }

    void RemoteReceiver::update()
    {
        static const int buffer_length = 5;

        if (_serial_interface->available())
        {
            uint8_t  buffer[buffer_length];
            //_serial_interface->readBytes(buffer, 1);

            //if (buffer[0] != 125) return;

            _serial_interface->readBytes(buffer, buffer_length);
            _joystick.deserialize(buffer, 0);
        }
    }
}

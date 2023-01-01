#include "remote.h"


namespace gldr
{
    Remote::Remote(int rx, int tx, long baud)
    {
        _serial_interface = new SoftwareSerial(rx, tx);
        _serial_interface->begin(baud);
    }
}

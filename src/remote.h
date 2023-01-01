#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "joystick.h"
#include "serializable.h"

namespace gldr
{
    class Remote
    {
    public:
        Remote(int rx, int tx, long baud);

    protected:
        SoftwareSerial* _serial_interface;
    };
}
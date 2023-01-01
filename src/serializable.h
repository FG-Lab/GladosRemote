#pragma once

#include "inttypes.h"


namespace gldr
{
    class Serializeable
    {
    public:
        virtual uint8_t* serialize(int& length_buffer) = 0;
    };
}


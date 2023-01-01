#pragma once

#include <inttypes.h>


namespace gldr
{
    class Deserializeable
    {
    public:
        virtual void deserialize(uint8_t* data, int index) = 0;
    };
}


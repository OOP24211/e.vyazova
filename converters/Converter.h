#pragma once
#include <cstdint>

class Converter {
public:
    virtual int16_t process(int16_t in, uint64_t index) = 0;
    virtual ~Converter() = default;
};
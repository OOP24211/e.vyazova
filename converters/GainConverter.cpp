#include "GainConverter.h"
#include <algorithm>


int16_t GainConverter::process(int16_t in, uint64_t) {
    int v = static_cast<int>(in * gain);
    return std::clamp(v, -32768, 32767);
}
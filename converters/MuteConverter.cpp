#include "MuteConverter.h"


MuteConverter::MuteConverter(double a, double b) {
    from = static_cast<uint64_t>(a * 44100);
    to = static_cast<uint64_t>(b * 44100);
}


int16_t MuteConverter::process(int16_t in, uint64_t idx) {
    return (idx >= from && idx < to) ? 0 : in;
}
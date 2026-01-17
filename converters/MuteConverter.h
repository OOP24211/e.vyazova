#ifndef LAB3_MUTECONVERTER_H
#define LAB3_MUTECONVERTER_H

#pragma once
#include "Converter.h"

class MuteConverter : public Converter {
    uint64_t from, to;
public:
    MuteConverter(double a, double b);
    int16_t process(int16_t in, uint64_t idx) override;
};

#endif //LAB3_MUTECONVERTER_H
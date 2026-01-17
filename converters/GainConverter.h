#ifndef LAB3_GAINCONVERTER_H
#define LAB3_GAINCONVERTER_H

#pragma once
#include "Converter.h"
class GainConverter : public Converter {
    double gain;
public:
    explicit GainConverter(double g) : gain(g) {}
    int16_t process(int16_t in, uint64_t) override;
};
#endif //LAB3_GAINCONVERTER_H
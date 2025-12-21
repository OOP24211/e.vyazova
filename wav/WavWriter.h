#ifndef LAB3_WAVWRITER_H
#define LAB3_WAVWRITER_H

#pragma once
#include <fstream>
#include <cstdint>
#include <string>

class WavWriter {
    std::ofstream out;
    uint32_t samples = 0;
public:
    explicit WavWriter(const std::string& path);
    void writeSample(int16_t s);
    void finalize();
};

#endif //LAB3_WAVWRITER_H
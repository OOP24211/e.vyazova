#ifndef LAB3_WAVREADER_H
#define LAB3_WAVREADER_H

#pragma once
#include <fstream>
#include <cstdint>
#include <string>

class WavReader {
    std::ifstream in;
public:
    explicit WavReader(const std::string& path);
    bool readSample(int16_t& sample);
};

#endif //LAB3_WAVREADER_H
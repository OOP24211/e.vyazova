#include "WavReader.h"
#include "../errors/Errors.h"

struct WavHeader {
    char riff[4];
    uint32_t size;
    char wave[4];
    char fmt[4];
    uint32_t fmtSize;
    uint16_t audioFormat;
    uint16_t channels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char data[4];
    uint32_t dataSize;
};


WavReader::WavReader(const std::string& path) {
    in.open(path, std::ios::binary);
    if (!in) throw WavFormatError("Cannot open WAV file");


    WavHeader h{};
    in.read(reinterpret_cast<char*>(&h), sizeof(h));


    if (std::string(h.riff,4)!="RIFF" || std::string(h.wave,4)!="WAVE")
        throw WavFormatError("Not a WAV file");
    if (h.audioFormat!=1 || h.channels!=1 || h.bitsPerSample!=16 || h.sampleRate!=44100)
        throw WavFormatError("Unsupported WAV format");
}

bool WavReader::readSample(int16_t& sample) {
    return bool(in.read(reinterpret_cast<char*>(&sample), sizeof(sample)));
}
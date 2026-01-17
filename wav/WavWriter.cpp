#include "WavWriter.h"


WavWriter::WavWriter(const std::string& path) {
    out.open(path, std::ios::binary);
    char header[44] = {};
    out.write(header, 44);
}


void WavWriter::writeSample(int16_t s) {
    out.write(reinterpret_cast<char*>(&s), sizeof(s));
    samples++;
}


void WavWriter::finalize() {
    out.seekp(0);
    uint32_t dataSize = samples * 2;
    out.write("RIFF",4);
    uint32_t size = 36 + dataSize;
    out.write(reinterpret_cast<char*>(&size),4);
    out.write("WAVEfmt ",8);
    uint32_t fmtSize=16; uint16_t pcm=1, ch=1, bps=16;
    uint32_t sr=44100, br=sr*2; uint16_t ba=2;
    out.write(reinterpret_cast<char*>(&fmtSize),4);
    out.write(reinterpret_cast<char*>(&pcm),2);
    out.write(reinterpret_cast<char*>(&ch),2);
    out.write(reinterpret_cast<char*>(&sr),4);
    out.write(reinterpret_cast<char*>(&br),4);
    out.write(reinterpret_cast<char*>(&ba),2);
    out.write(reinterpret_cast<char*>(&bps),2);
    out.write("data",4);
    out.write(reinterpret_cast<char*>(&dataSize),4);
}
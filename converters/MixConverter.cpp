#include "Converter.h"
#include <vector>
#include <cstdint>

class MixConverter : public Converter {
    int streamNumber_;
    uint64_t start_;
    std::vector<int16_t> extraSamples_;
public:
    //streamNumber — номер входного потока ($n)
    //startSec — смещение в секундах
    //allInputs — вектор всех входных файлов (сэмплы)
    MixConverter(int streamNumber, double startSec,
                 const std::vector<std::vector<int16_t>>& allInputs)
        : streamNumber_(streamNumber), start_(static_cast<uint64_t>(startSec * 44100))
    {
        extraSamples_ = allInputs[streamNumber_ - 1];
    }

    int16_t process(int16_t in, uint64_t idx) override {
        if (idx < start_ || idx - start_ >= extraSamples_.size())
            return in;
        int16_t other = extraSamples_[idx - start_];
        int32_t mixed = (int32_t(in) + int32_t(other)) / 2;
        if (mixed > 32767) mixed = 32767;
        if (mixed < -32768) mixed = -32768;
        return static_cast<int16_t>(mixed);
    }
};

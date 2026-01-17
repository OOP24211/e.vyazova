#include "ProcessingPipeline.h"


void ProcessingPipeline::run(WavReader& in, WavWriter& out,
std::vector<std::unique_ptr<Converter>>& convs) {
    int16_t s;
    uint64_t idx = 0;
    while (in.readSample(s)) {
        for (auto& c : convs)
            s = c->process(s, idx);
        out.writeSample(s);
        idx++;
    }
    out.finalize();
}
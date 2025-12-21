#include "wav/WavReader.h"
#include "wav/WavWriter.h"
#include "config/ConfigParser.h"
#include "pipeline/ProcessingPipeline.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    try {
        if (argc < 5 || std::string(argv[1]) != "-c")
            throw std::runtime_error("Usage: sound_processor -c config.txt out.wav in.wav [in2.wav ...]");

        std::vector<std::vector<int16_t>> allInputs;
        for (int i = 4; i < argc; ++i) {
            WavReader r(argv[i]);
            std::vector<int16_t> samples;
            int16_t s;
            while (r.readSample(s)) samples.push_back(s);
            allInputs.push_back(samples);
        }
        auto converters = ConfigParser::parse(argv[2], allInputs);

        WavReader input(argv[4]);
        WavWriter output(argv[3]);
        ProcessingPipeline::run(input, output, converters);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
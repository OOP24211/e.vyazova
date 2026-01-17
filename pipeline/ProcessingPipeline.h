#ifndef LAB3_PROCESSINGPIPELINE_H
#define LAB3_PROCESSINGPIPELINE_H

#pragma once
#include <vector>
#include <memory>
#include "../converters/Converter.h"
#include "../wav/WavReader.h"
#include "../wav/WavWriter.h"


class ProcessingPipeline {
public:
    static void run(WavReader& in, WavWriter& out,
    std::vector<std::unique_ptr<Converter>>& convs);
};

#endif //LAB3_PROCESSINGPIPELINE_H
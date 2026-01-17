#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Converter.h"

class ConverterFactory {
public:
    static std::unique_ptr<Converter> create(
        const std::vector<std::string>& tokens,
        const std::vector<std::vector<int16_t>>& allInputs
    );
};

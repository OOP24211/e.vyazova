#ifndef LAB3_CONFIGPARSER_H
#define LAB3_CONFIGPARSER_H

#pragma once
#include <vector>
#include <string>
#include <memory>
#include "../converters/Converter.h"

class ConfigParser {
public:
    static std::vector<std::unique_ptr<Converter>> parse(
        const std::string& path,
        const std::vector<std::vector<int16_t>>& allInputs
    );
};

#endif //LAB3_CONFIGPARSER_H
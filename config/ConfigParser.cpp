#include "ConfigParser.h"
#include <fstream>
#include <sstream>
#include "../converters/ConverterFactory.h"
#include "../errors/Errors.h"

std::vector<std::unique_ptr<Converter>> ConfigParser::parse(
    const std::string& path,
    const std::vector<std::vector<int16_t>>& allInputs
) {
    std::ifstream in(path);
    if (!in) throw ConfigError("Cannot open config file");

    std::vector<std::unique_ptr<Converter>> res;
    std::string line;
    while (getline(in, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream iss(line);
        std::vector<std::string> t;
        for (std::string s; iss >> s;) t.push_back(s);
        res.push_back(ConverterFactory::create(t, allInputs));
    }
    return res;
}

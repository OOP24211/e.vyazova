#include "ConverterFactory.h"
#include "MuteConverter.h"
#include "GainConverter.h"
#include "MixConverter.h"
#include "../errors/Errors.h"
#include <cstdlib>

std::unique_ptr<Converter> ConverterFactory::create(
    const std::vector<std::string>& t,
    const std::vector<std::vector<int16_t>>& allInputs
) {
    if (t[0] == "mute" && t.size() == 3)
        return std::make_unique<MuteConverter>(std::stod(t[1]), std::stod(t[2]));

    if (t[0] == "gain" && t.size() == 2)
        return std::make_unique<GainConverter>(std::stod(t[1]));

    if (t[0] == "mix" && t.size() == 3 && t[1][0] == '$') {
        int n = std::stoi(t[1].substr(1));
        double startSec = std::stod(t[2]);
        return std::make_unique<MixConverter>(n, startSec, allInputs);
    }

    throw ConfigError("Invalid converter configuration");

}


#include <gtest/gtest.h>
#include "converters/ConverterFactory.h"
#include "errors/Errors.h"

TEST(ConverterFactoryTest, CreateGain) {
    std::vector<std::string> t = {"gain", "2.0"};
    std::vector<std::vector<int16_t>> inputs;

    auto c = ConverterFactory::create(t, inputs);
    EXPECT_NE(c, nullptr);
}

TEST(ConverterFactoryTest, InvalidConfigThrows) {
    std::vector<std::string> t = {"gain"};
    std::vector<std::vector<int16_t>> inputs;

    EXPECT_THROW(
        ConverterFactory::create(t, inputs),
        ConfigError
    );
}
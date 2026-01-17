#include <gtest/gtest.h>
#include "converters/MixConverter.h"
#include "../errors/Errors.h"

TEST(MixConverterTest, NoMixBeforeStart) {
    std::vector<std::vector<int16_t>> inputs = {{100, 100, 100}};
    MixConverter m(1, 1.0, inputs); // start = 44100

    EXPECT_EQ(m.process(200, 0), 200);
}

TEST(MixConverterTest, MixingWorks) {
    std::vector<std::vector<int16_t>> inputs = {{100, 100, 100}};
    MixConverter m(1, 0.0, inputs);

    EXPECT_EQ(m.process(300, 0), 200); // (300 + 100) / 2
}

TEST(MixConverterTest, MixClamping) {
    std::vector<std::vector<int16_t>> inputs = {{32767}};
    MixConverter m(1, 0.0, inputs);

    EXPECT_EQ(m.process(32767, 0), 32767);
}
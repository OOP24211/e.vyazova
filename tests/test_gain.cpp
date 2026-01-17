#include <gtest/gtest.h>
#include "converters/GainConverter.h"
#include "../errors/Errors.h"

TEST(GainConverterTest, IdentityGain) {
    GainConverter g(1.0);
    EXPECT_EQ(g.process(1000, 0), 1000);
}

TEST(GainConverterTest, Amplification) {
    GainConverter g(2.0);
    EXPECT_EQ(g.process(1000, 0), 2000);
}

TEST(GainConverterTest, ClippingUpper) {
    GainConverter g(10.0);
    EXPECT_EQ(g.process(4000, 0), 32767);
}

TEST(GainConverterTest, ClippingLower) {
    GainConverter g(10.0);
    EXPECT_EQ(g.process(-4000, 0), -32768);
}

#include <gtest/gtest.h>
#include "converters/MuteConverter.h"
#include "../errors/Errors.h"

TEST(MuteConverterTest, OutsideRange) {
    MuteConverter m(1.0, 2.0); // 44100 .. 88200
    EXPECT_EQ(m.process(1234, 0), 1234);
}

TEST(MuteConverterTest, InsideRange) {
    MuteConverter m(1.0, 2.0);
    EXPECT_EQ(m.process(1234, 50000), 0);
}

TEST(MuteConverterTest, BoundaryConditions) {
    MuteConverter m(1.0, 2.0);
    EXPECT_EQ(m.process(1234, 44100), 0);
    EXPECT_EQ(m.process(1234, 88200), 1234);
}

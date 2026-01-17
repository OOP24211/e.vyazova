#include <gtest/gtest.h>
#include <fstream>
#include "config/ConfigParser.h"
#include "../errors/Errors.h"

TEST(ConfigParserTest, ParseValidConfig) {
    std::ofstream cfg("test.cfg");
    cfg << "# comment\n";
    cfg << "gain 2.0\n";
    cfg << "mute 0.0 1.0\n";
    cfg.close();

    std::vector<std::vector<int16_t>> inputs;
    auto res = ConfigParser::parse("test.cfg", inputs);

    EXPECT_EQ(res.size(), 2);
}

TEST(ConfigParserTest, MissingFileThrows) {
    std::vector<std::vector<int16_t>> inputs;
    EXPECT_THROW(
        ConfigParser::parse("no_such_file.cfg", inputs),
        ConfigError
    );
}

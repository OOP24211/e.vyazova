cmake_minimum_required(VERSION 3.16)
project(UnitTests)

find_package(GTest REQUIRED PATHS /opt/homebrew/opt/googletest NO_DEFAULT_PATH)

add_executable(unit_tests
        test_gain.cpp
        test_mute.cpp
        test_mix.cpp
        test_factory.cpp
        test_config_parser.cpp
        test_pipeline.cpp
)

target_link_libraries(unit_tests
        PRIVATE
        sound_lib
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(unit_tests
        PRIVATE
        ${CMAKE_SOURCE_DIR}
)

add_test(NAME unit_tests COMMAND unit_tests)

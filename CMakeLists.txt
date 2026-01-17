cmake_minimum_required(VERSION 3.16)
project(sound_processor)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(tests)

add_library(sound_lib
        wav/WavReader.cpp
        wav/WavWriter.cpp
        converters/MuteConverter.cpp
        converters/MixConverter.cpp
        converters/GainConverter.cpp
        converters/ConverterFactory.cpp
        config/ConfigParser.cpp
        pipeline/ProcessingPipeline.cpp
)

add_executable(sound_processor main.cpp)
target_link_libraries(sound_processor PRIVATE sound_lib)
cmake_minimum_required(VERSION 3.16)
project(sound_processor)


set(CMAKE_CXX_STANDARD 17)


add_executable(sound_processor
        main.cpp
        wav/WavReader.cpp
        wav/WavWriter.cpp
        converters/MuteConverter.cpp
        converters/MixConverter.cpp
        converters/GainConverter.cpp
        converters/ConverterFactory.cpp
        config/ConfigParser.cpp
        pipeline/ProcessingPipeline.cpp
        errors/Errors.h
        wav/WavReader.h
        wav/WavReader.cpp
        wav/WavWriter.h
        wav/WavWriter.cpp
        converters/Converter.h
        converters/GainConverter.h
        converters/MuteConverter.cpp
        converters/MixConverter.h
        converters/MixConverter.cpp
        converters/GainConverter.h
        converters/MuteConverter.h
        converters/GainConverter.cpp
        converters/ConverterFactory.h
        converters/ConverterFactory.cpp
        config/ConfigParser.h
        config/ConfigParser.cpp
        pipeline/ProcessingPipeline.h
        pipeline/ProcessingPipeline.cpp
)
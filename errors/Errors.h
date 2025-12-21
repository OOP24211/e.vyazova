#ifndef LAB3_ERRORS_H
#define LAB3_ERRORS_H

#pragma once
#include <exception>
#include <string>

class SoundProcessorError : public std::exception {
protected:
    std::string msg;
public:
    explicit SoundProcessorError(std::string m) : msg(std::move(m)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};


class WavFormatError : public SoundProcessorError {
public:
    using SoundProcessorError::SoundProcessorError;
};


class ConfigError : public SoundProcessorError {
public:
    using SoundProcessorError::SoundProcessorError;
};


#endif //LAB3_ERRORS_H
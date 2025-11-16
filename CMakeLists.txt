cmake_minimum_required(VERSION 4.0)
project(ICache)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

add_library(ICacheLib
        GeneralClass.cpp
        GeneralClass.hpp
        FibonachhiCacheLFU.cpp
        FibonachhiCacheLFU.hpp
        FibonachhiCacheLRU.cpp
        FibonachhiCacheLRU.hpp
        ICache.hpp
)

add_executable(ICache main.cpp)
target_link_libraries(ICache ICacheLib)

add_executable(ICacheTests tests.cpp)
target_link_libraries(ICacheTests
        ICacheLib
        gtest
        gtest_main
        gmock
)

target_include_directories(ICacheTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include
)

if(NOT WIN32)
    target_link_libraries(ICacheTests pthread)
endif()
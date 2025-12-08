cmake_minimum_required(VERSION 3.16)
project(kind_cat)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 REQUIRED graphics window system)

add_executable(kind_cat main.cpp
        Cat.h
        Mouse.h
        Cat.cpp
        Constants.h
        Game.h
        Game.cpp
)

target_link_libraries(kind_cat PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

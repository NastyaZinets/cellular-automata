
cmake_minimum_required(VERSION 3.16)

project(GrayScott)

set( CMAKE_CXX_STANDARD 20)

add_executable(
    GrayScott
    src/main.cpp
    src/simulation.cpp
    src/rendering.cpp
)

find_package(SDL2 REQUIRED)

target_link_libraries(
    GrayScott
    PRIVATE
    SDL2::SDL2
)





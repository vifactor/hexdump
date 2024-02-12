cmake_minimum_required(VERSION 3.15)

project(Hexdump)

set(CMAKE_CXX_STANDARD 20)

find_package(fmt)

add_executable(hexdump 
    main.cpp
    hexdump20.cpp
    hexdump20.hpp
)

target_link_libraries(hexdump fmt::fmt)
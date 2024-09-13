cmake_minimum_required(VERSION 3.15)

project(Hexdump)

set(CMAKE_CXX_STANDARD 20)

find_package(fmt)
find_package(benchmark)

# library
add_library(hexdump_lib
    hexdump20.cpp
    hexdump20.hpp
    hexdump17.cpp
    hexdump17.hpp
)
target_link_libraries(hexdump_lib fmt::fmt)

# main executable
add_executable(hexdump_main 
    main.cpp
)
target_link_libraries(hexdump_main hexdump_lib)

# benchmark
add_executable(hexdump_benchmark 
    benchmark.cpp
)
target_link_libraries(hexdump_benchmark hexdump_lib benchmark::benchmark)

add_executable(guard guard.cpp)
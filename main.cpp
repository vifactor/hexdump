#include "hexdump20.hpp"
#include "hexdump17.hpp"

#include <numeric>
#include <iostream>

int main(int argc, char** argv) {
    std::vector<uint8_t> data;
    data.resize(255);
    std::iota(data.begin(), data.end(), 0);

    std::cout << "c++17:" << std::endl;
    cpp17::hexdump(std::cout, data);

    std::cout << "c++20:"<< std::endl;
    cpp20::hexdump(std::cout, data);
    return EXIT_SUCCESS;
}
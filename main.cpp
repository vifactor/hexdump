#include "hexdump20.hpp"

#include <vector>
#include <cstdint>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <iomanip>


void hexdump(const std::vector<uint8_t>& ba) {
  for (int i = 0; i < ba.size(); i += 16) {
    std::cout << std::hex << std::setfill('0') << std::setw(6) << i << " ";
    for (int j = 0; j < 16; j++) 
      if (i + j < ba.size()) {
        int val = ba[i+j];
        std::cout << std::hex << std::setfill('0') << std::setw(2) << val << " ";
      }
      else
        std::cout << "   ";
    std::cout << " |";
    for (int j = 0; j < 16; j++) 
      if (i + j < ba.size()) {
        char c = ba[i + j];
        std::cout << (std::isprint(c) ? c : '.');
      }
    std::cout << "|\n";
  }
}

int main(int argc, char** argv) {
    std::vector<uint8_t> data;
    data.resize(135);
    std::iota(data.begin(), data.end(), 0);

    hexdump(data);
    std::cout << "bla-bla" << 16 << std::endl;

    std::cout << std::endl;
    cpp20::hexdump(data);
    return EXIT_SUCCESS;
}
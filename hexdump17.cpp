#include "hexdump17.hpp"

#include <iomanip>
#include <ostream>
namespace cpp17 {

void hexdump(std::ostream& os, const std::vector<uint8_t>& ba) {
  // there is a bug here: stream flags should be restored
  for (int i = 0; i < ba.size(); i += 16) {
    os << std::hex << std::setfill('0') << std::setw(6) << i << " ";
    for (int j = 0; j < 16; j++) 
      if (i + j < ba.size()) {
        int val = ba[i+j];
        os << std::hex << std::setfill('0') << std::setw(2) << val << " ";
      }
      else
        os << "   ";
    os << " |";
    for (int j = 0; j < 16; j++) 
      if (i + j < ba.size()) {
        char c = ba[i + j];
        os << (std::isprint(c) ? c : '.');
      }
    os << "|\n";
  }
}
}
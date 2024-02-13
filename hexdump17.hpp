#pragma once

#include <vector>
#include <cstdint>
#include <iosfwd>

namespace cpp17 {
void hexdump(std::ostream& , const std::vector<uint8_t>& ba);
}
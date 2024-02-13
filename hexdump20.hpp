#pragma once

#include <cstdint>
#include <span>
#include <iosfwd>

namespace cpp20 {
void hexdump(std::ostream&s, std::span<const uint8_t>);
}
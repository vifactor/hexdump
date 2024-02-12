#pragma once

#include <cstdint>
#include <span>

namespace cpp20 {
void hexdump(std::span<const uint8_t>);
}
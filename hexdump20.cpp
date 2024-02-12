#include "hexdump20.hpp"

#include <ranges>

#include <fmt/ranges.h>

#include <iomanip>
#include <iostream>

namespace cpp20 {
namespace {
void hexdump_row(size_t row, std::span<const uint8_t> arr) {

    const auto ascii = arr | std::ranges::views::transform([](uint8_t el) {
        char c = el;
        return std::isprint(c) ? c : '.';
    });
    int count = 2 + (16 - arr.size()) * 3;
    fmt::print("{:06x} {:02x}{: >{}}|{}|\n", row, fmt::join(arr, " "), "", count, fmt::join(ascii, ""));
}
}

void hexdump(std::span<const uint8_t> s) {
    constexpr size_t maxElPerRow = 16;
    for (size_t i = 0; i < s.size(); i += maxElPerRow) {
        hexdump_row(i, s.subspan(i, std::min(maxElPerRow, s.size() - i)));
    }
}
}
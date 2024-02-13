#include "hexdump20.hpp"
#include "hexdump17.hpp"

#include <benchmark/benchmark.h>

#include <numeric>
#include <sstream>

std::vector<uint8_t> makeData(size_t sz) {
    std::vector<uint8_t> data;
    data.resize(135);
    std::iota(data.begin(), data.end(), 0);
    return data;
}

static void BM_Hexdump20(benchmark::State& state) {
    const std::vector<uint8_t> data = makeData(135);
    std::ostringstream stream;
    for (auto _ : state) {
        cpp20::hexdump(stream, data);
        stream.str("");
    }
}
BENCHMARK(BM_Hexdump20);

static void BM_Hexdump17(benchmark::State& state) {
    const std::vector<uint8_t> data = makeData(135);
    std::ostringstream stream;
    for (auto _ : state) {
        cpp17::hexdump(stream, data);
        stream.str("");
    }
}
BENCHMARK(BM_Hexdump17);

BENCHMARK_MAIN();
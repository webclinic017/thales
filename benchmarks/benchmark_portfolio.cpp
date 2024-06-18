/*
 * MIT License
 *
 * Copyright (c) 2024 Cody Michael Jones
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <benchmark/benchmark.h>
#include "trading/portfolio.h"
#include "trading/position.h"
#include <vector>

static void BM_PortfolioConstruction(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<thales::Position> positions = {
            thales::Position("AAPL", "Call", 150.0, "2024-12-15", 10, 5.0),
            thales::Position("TSLA", "Put", 700.0, "2024-12-15", 5, 10.0)
        };
        thales::Portfolio portfolio(10000.0, positions);
        benchmark::DoNotOptimize(portfolio);
    }
}
BENCHMARK(BM_PortfolioConstruction);

static void BM_PortfolioGetValue(benchmark::State& state) {
    std::vector<thales::Position> positions = {
        thales::Position("AAPL", "Call", 150.0, "2024-12-15", 10, 5.0),
        thales::Position("TSLA", "Put", 700.0, "2024-12-15", 5, 10.0)
    };
    thales::Portfolio portfolio(10000.0, positions);
    for (auto _ : state) {
        double value = portfolio.get_value();
        benchmark::DoNotOptimize(value);
    }
}
BENCHMARK(BM_PortfolioGetValue);

static void BM_PortfolioGetPositions(benchmark::State& state) {
    std::vector<thales::Position> positions = {
        thales::Position("AAPL", "Call", 150.0, "2024-12-15", 10, 5.0),
        thales::Position("TSLA", "Put", 700.0, "2024-12-15", 5, 10.0)
    };
    thales::Portfolio portfolio(10000.0, positions);
    for (auto _ : state) {
        auto pos = portfolio.get_positions();
        benchmark::DoNotOptimize(pos);
    }
}
BENCHMARK(BM_PortfolioGetPositions);

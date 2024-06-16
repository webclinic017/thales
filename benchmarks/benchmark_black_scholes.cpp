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
#include "trading/black_scholes.h"

static void BM_BlackScholesCall(benchmark::State& state) {
    BlackScholes bs;

    double S = 100.0;   // Current stock price
    double K = 100.0;   // Strike price
    double T = 1.0;     // Time to maturity (in years)
    double r = 0.05;    // Risk-free interest rate
    double sigma = 0.2; // Volatility

    for (auto _ : state) {
        double call_price = bs.calculate_option_price(S, K, T, r, sigma, CALL);
        benchmark::DoNotOptimize(call_price);
    }
}
BENCHMARK(BM_BlackScholesCall);

static void BM_BlackScholesPut(benchmark::State& state) {
    BlackScholes bs;

    double S = 100.0;   // Current stock price
    double K = 100.0;   // Strike price
    double T = 1.0;     // Time to maturity (in years)
    double r = 0.05;    // Risk-free interest rate
    double sigma = 0.2; // Volatility

    for (auto _ : state) {
        double put_price = bs.calculate_option_price(S, K, T, r, sigma, PUT);
        benchmark::DoNotOptimize(put_price);
    }
}
BENCHMARK(BM_BlackScholesPut);

BENCHMARK_MAIN();

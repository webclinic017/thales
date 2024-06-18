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

#include "trading/black_scholes.h"

#include <cmath>
#include <stdexcept>

double BlackScholes::calculate_option_price(double S, double K, double T,
                                            double r, double sigma,
                                            OptionType type) {
    if (S <= 0 || K <= 0 || T < 0 || sigma < 0) {
        throw std::invalid_argument("Invalid input parameters");
    }

    double d1 =
        (log(S / K) + (r + sigma * sigma / 2.0) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    switch (type) {
        case CALL:
            return S * 0.5 * (1 + erf(d1 / sqrt(2))) -
                   K * exp(-r * T) * 0.5 * (1 + erf(d2 / sqrt(2)));
        case PUT:
            return K * exp(-r * T) * 0.5 * (1 + erf(-d2 / sqrt(2))) -
                   S * 0.5 * (1 + erf(-d1 / sqrt(2)));
        default:
            throw std::invalid_argument("Invalid option type");
    }
}

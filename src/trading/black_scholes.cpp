// SPDX-License-Identifier: MIT

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

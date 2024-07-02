// SPDX-License-Identifier: MIT

#pragma once

#include <cmath>

/**
 * @brief Option types
 */
enum OptionType {
    CALL, /**< Call option */
    PUT   /**< Put option */
};

/**
 * @brief Black-Scholes model for option pricing
 */
class BlackScholes {
   public:
    /**
     * @brief Calculate the price of an option using the Black-Scholes model
     *
     * @param S Current stock price
     * @param K Strike price
     * @param T Time to maturity (in years)
     * @param r Risk-free interest rate
     * @param sigma Volatility
     * @param type Option type (CALL or PUT)
     * @return double Option price
     */
    static double calculate_option_price(double S, double K, double T, double r,
                                         double sigma, OptionType type);
};

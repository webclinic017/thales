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

#include <gtest/gtest.h>

#include <cmath>

#include "trading/black_scholes.h"

class BlackScholesTest : public ::testing::Test {
   protected:
    BlackScholes bs;
};

TEST_F(BlackScholesTest, CalculateOptionPrice) {
    double S = 100.0;    // Current stock price
    double K = 100.0;    // Strike price
    double T = 1.0;      // Time to maturity (in years)
    double r = 0.05;     // Risk-free interest rate
    double sigma = 0.2;  // Volatility

    double call_price = bs.calculate_option_price(S, K, T, r, sigma, CALL);
    double put_price = bs.calculate_option_price(S, K, T, r, sigma, PUT);

    ASSERT_GT(call_price, 0);
    ASSERT_GT(put_price, 0);
}

TEST_F(BlackScholesTest, DeepInTheMoneyPutOption) {
    double S = 50.0;     // Current stock price
    double K = 100.0;    // Strike price
    double T = 1.0;      // Time to maturity (in years)
    double r = 0.05;     // Risk-free interest rate
    double sigma = 0.2;  // Volatility

    double put_price = bs.calculate_option_price(S, K, T, r, sigma, PUT);
    double expected_put_price =
        K * exp(-r * T) - S;  // Adjusted expected value calculation
    ASSERT_NEAR(put_price, expected_put_price, 1e-2);
}

TEST_F(BlackScholesTest, ZeroVolatility) {
    double S = 100.0;    // Current stock price
    double K = 100.0;    // Strike price
    double T = 1.0;      // Time to maturity (in years)
    double r = 0.05;     // Risk-free interest rate
    double sigma = 0.0;  // Zero volatility

    double call_price = bs.calculate_option_price(S, K, T, r, sigma, CALL);
    double put_price = bs.calculate_option_price(S, K, T, r, sigma, PUT);

    double expected_call_price = std::max(0.0, S - K * exp(-r * T));
    double expected_put_price = std::max(0.0, K * exp(-r * T) - S);

    ASSERT_NEAR(call_price, expected_call_price, 1e-6);
    ASSERT_NEAR(put_price, expected_put_price, 1e-6);
}

TEST_F(BlackScholesTest, ZeroInterestRate) {
    double S = 100.0;    // Current stock price
    double K = 100.0;    // Strike price
    double T = 1.0;      // Time to maturity (in years)
    double r = 0.0;      // Zero interest rate
    double sigma = 0.2;  // Volatility

    double call_price = bs.calculate_option_price(S, K, T, r, sigma, CALL);
    double put_price = bs.calculate_option_price(S, K, T, r, sigma, PUT);

    ASSERT_GT(call_price, 0);
    ASSERT_GT(put_price, 0);
}

TEST_F(BlackScholesTest, NearExpiry) {
    double S = 100.0;    // Current stock price
    double K = 100.0;    // Strike price
    double T = 0.01;     // Near expiry (in years)
    double r = 0.05;     // Risk-free interest rate
    double sigma = 0.2;  // Volatility

    double call_price = bs.calculate_option_price(S, K, T, r, sigma, CALL);
    double put_price = bs.calculate_option_price(S, K, T, r, sigma, PUT);

    ASSERT_GT(call_price, 0);
    ASSERT_GT(put_price, 0);
}

TEST_F(BlackScholesTest, LongTimeToExpiry) {
    double S = 100.0;    // Current stock price
    double K = 100.0;    // Strike price
    double T = 10.0;     // Long time to maturity (in years)
    double r = 0.05;     // Risk-free interest rate
    double sigma = 0.2;  // Volatility

    double call_price = bs.calculate_option_price(S, K, T, r, sigma, CALL);
    double put_price = bs.calculate_option_price(S, K, T, r, sigma, PUT);

    ASSERT_GT(call_price, 0);
    ASSERT_GT(put_price, 0);
}

TEST(BlackScholesTest, InvalidOptionType) {
    EXPECT_THROW(
        BlackScholes::calculate_option_price(100.0, 100.0, 1.0, 0.05, 0.2, static_cast<OptionType>(-1)),
        std::invalid_argument
    );
}

TEST(BlackScholesTest, InvalidInputParameters) {
    EXPECT_THROW(
        BlackScholes::calculate_option_price(-100.0, 100.0, 1.0, 0.05, 0.2, OptionType::CALL),
        std::invalid_argument
    );
    EXPECT_THROW(
        BlackScholes::calculate_option_price(100.0, -100.0, 1.0, 0.05, 0.2, OptionType::CALL),
        std::invalid_argument
    );
    EXPECT_THROW(
        BlackScholes::calculate_option_price(100.0, 100.0, -1.0, 0.05, 0.2, OptionType::CALL),
        std::invalid_argument
    );
    EXPECT_THROW(
        BlackScholes::calculate_option_price(100.0, 100.0, 1.0, 0.05, -0.2, OptionType::CALL),
        std::invalid_argument
    );
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

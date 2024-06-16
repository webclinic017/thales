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

#pragma once

#include <vector>

#include "position.h"

namespace thales {

/**
 * @brief Represents the user's portfolio.
 */
class Portfolio {
   public:
    Portfolio(double value, const std::vector<Position>& positions);

    double get_value() const;
    std::vector<Position> get_positions() const;

   private:
    double value; /**< The total value of the portfolio. */
    std::vector<Position>
        positions; /**< The list of options positions in the portfolio. */
};

/**
 * @brief Fetches the current portfolio information.
 *
 * @return The current portfolio.
 */
Portfolio fetch_portfolio();

/**
 * @brief Fetches the list of recently executed orders.
 *
 * @return A list of recently executed orders.
 */
std::vector<Order> fetch_orders();

/**
 * @brief Displays the portfolio information.
 *
 * @param portfolio The portfolio to display.
 */
void display_portfolio(const Portfolio& portfolio);

/**
 * @brief Displays the list of recently executed orders.
 *
 * @param orders The list of orders to display.
 */
void display_orders(const std::vector<Order>& orders);

}  // namespace thales

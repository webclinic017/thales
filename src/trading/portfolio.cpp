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

#include "trading/portfolio.h"

#include <iostream>
#include <vector>

#include "trading/order.h"

namespace thales {

/**
 * @brief Constructs a Portfolio object.
 */
Portfolio::Portfolio(double value, const std::vector<Position>& positions)
    : value(value), positions(positions) {}

/**
 * @brief Getters for Portfolio class members.
 */
double Portfolio::get_value() const { return value; }
std::vector<Position> Portfolio::get_positions() const { return positions; }

/**
 * @brief Fetches the current portfolio information.
 *
 * This is a simulated function that generates a portfolio with predefined
 * values.
 *
 * @return The current portfolio.
 */
Portfolio fetch_portfolio() {
    Portfolio portfolio(
        10000.0, {Position("AAPL", "Call", 150.0, "2024-12-15", 10, 5.0),
                  Position("TSLA", "Put", 700.0, "2024-12-15", 5, 10.0)});
    return portfolio;
}

/**
 * @brief Fetches the list of recently executed orders.
 *
 * This is a simulated function that generates a list of orders with predefined
 * values.
 *
 * @return A list of recently executed orders.
 */
std::vector<Order> fetch_orders() {
    static int count = 0;
    std::vector<Order> orders;
    orders.push_back(Order("Buy", "AAPL", "Call", 150.0, "2024-12-15", 10, 5.0,
                           "2024-06-15T10:15:00Z"));
    if (++count % 2 == 0) {
        orders.push_back(Order("Sell", "TSLA", "Put", 700.0, "2024-12-15", 5,
                               10.0, "2024-06-15T10:16:00Z"));
    }
    return orders;
}

/**
 * @brief Displays the portfolio information.
 *
 * @param portfolio The portfolio to display.
 */
void display_portfolio(const Portfolio& portfolio) {
    std::cout << "Portfolio Value: $" << portfolio.get_value()
              << "\nPositions:\n";
    for (const auto& position : portfolio.get_positions()) {
        std::cout << "  " << position.get_symbol() << " "
                  << position.get_option_type() << " "
                  << position.get_strike_price() << " @ "
                  << position.get_expiration_date() << ": "
                  << position.get_quantity() << " contracts @ $"
                  << position.get_premium() << "\n";
    }
}

/**
 * @brief Displays the list of recently executed orders.
 *
 * @param orders The list of orders to display.
 */
void display_orders(const std::vector<Order>& orders) {
    std::cout << "Recent Orders:\n";
    for (const auto& order : orders) {
        std::cout << "  " << order.get_timestamp() << " - "
                  << order.get_action() << " " << order.get_quantity() << " "
                  << order.get_symbol() << " " << order.get_option_type() << " "
                  << order.get_strike_price() << " @ "
                  << order.get_expiration_date() << " for $"
                  << order.get_premium() << " each\n";
    }
}

}  // namespace thales

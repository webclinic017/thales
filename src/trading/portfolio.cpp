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
#include <iomanip>
#include <vector>

#include "trading/order.h"

namespace thales {

/**
 * @brief Constructs a Portfolio object.
 */
Portfolio::Portfolio(double net_liquidity, const std::vector<Position>& positions)
    : net_liquidity(net_liquidity), positions(positions) {}

/**
 * @brief Getters for Portfolio class members.
 */
double Portfolio::get_net_liquidity() const { return net_liquidity; }
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
   // Display the header
    std::cout << std::left << std::setw(10) << "Symbol"
              << std::setw(10) << "Type"
              << std::setw(10) << "Strike"
              << std::setw(15) << "Expiration"
              << std::setw(10) << "Quantity"
              << std::setw(10) << "Premium"
              << std::endl;

    std::cout << std::string(65, '-') << std::endl;

    // Display the portfolio positions
    for (const auto& position : portfolio.get_positions()) {
        std::cout << std::left << std::setw(10) << position.get_symbol()
                  << std::setw(10) << position.get_option_type()
                  << std::setw(10) << position.get_strike_price()
                  << std::setw(15) << position.get_expiration_date()
                  << std::setw(10) << position.get_quantity()
                  << std::setw(10) << position.get_premium()
                  << std::endl;
    }

    // Display the net liquidity
    std::cout << std::string(65, '-') << std::endl;
    std::cout << std::left << std::setw(55) << "Net Liquidity: " << "$" << portfolio.get_net_liquidity() << std::endl;
}

/**
 * @brief Displays the list of recently executed orders.
 *
 * @param orders The list of orders to display.
 */
void display_orders(const std::vector<Order>& orders) {
    std::cout << "Recent orders:\n";
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

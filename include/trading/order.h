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

#include <string>

namespace thales {

/**
 * @brief Represents a single options order executed by the trading bot.
 */
class Order {
   public:
    Order(const std::string& action, const std::string& symbol,
          const std::string& option_type, double strike_price,
          const std::string& expiration_date, int quantity, double premium,
          const std::string& timestamp);

    std::string get_action() const;
    std::string get_symbol() const;
    std::string get_option_type() const;
    double get_strike_price() const;
    std::string get_expiration_date() const;
    int get_quantity() const;
    double get_premium() const;
    std::string get_timestamp() const;

   private:
    std::string action;      /**< The action taken (e.g., Buy or Sell). */
    std::string symbol;      /**< The symbol of the underlying security. */
    std::string option_type; /**< The type of the option (e.g., Call or Put). */
    double strike_price;     /**< The strike price of the option. */
    std::string expiration_date; /**< The expiration date of the option. */
    int quantity;                /**< The number of option contracts traded. */
    double premium;              /**< The premium paid per option contract. */
    std::string timestamp;       /**< The timestamp of the order execution. */
};

}  // namespace thales

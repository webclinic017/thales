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

#include "trading/order.h"

namespace thales {

Order::Order(const std::string& action, const std::string& symbol,
             const std::string& option_type, double strike_price,
             const std::string& expiration_date, int quantity, double premium,
             const std::string& timestamp)
    : action(action),
      symbol(symbol),
      option_type(option_type),
      strike_price(strike_price),
      expiration_date(expiration_date),
      quantity(quantity),
      premium(premium),
      timestamp(timestamp) {}

std::string Order::get_action() const { return action; }
std::string Order::get_symbol() const { return symbol; }
std::string Order::get_option_type() const { return option_type; }
double Order::get_strike_price() const { return strike_price; }
std::string Order::get_expiration_date() const { return expiration_date; }
int Order::get_quantity() const { return quantity; }
double Order::get_premium() const { return premium; }
std::string Order::get_timestamp() const { return timestamp; }

}  // namespace thales

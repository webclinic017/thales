// SPDX-License-Identifier: MIT

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

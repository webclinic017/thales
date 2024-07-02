// SPDX-License-Identifier: MIT

#include "trading/option.h"

namespace thales {

Option::Option(const std::string& symbol, OptionType type, double strike_price,
               const std::string& expiration_date, double premium)
    : symbol(symbol),
      type(type),
      strike_price(strike_price),
      expiration_date(expiration_date),
      premium(premium) {}

const std::string& Option::get_symbol() const { return symbol; }

Option::OptionType Option::get_type() const { return type; }

double Option::get_strike_price() const { return strike_price; }

const std::string& Option::get_expiration_date() const {
    return expiration_date;
}

double Option::get_premium() const { return premium; }

}  // namespace thales

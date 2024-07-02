// SPDX-License-Identifier: MIT

#include "trading/position.h"

namespace thales {

Position::Position(const Option& option, int quantity)
    : option(option), quantity(quantity) {}

const Option& Position::get_option() const {
    return option;
}

int Position::get_quantity() const {
    return quantity;
}

}  // namespace thales

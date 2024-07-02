// SPDX-License-Identifier: MIT

#pragma once

#include "option.h"

namespace thales {

/**
 * @class Position
 * @brief Represents a position in an options contract.
 */
class Position {
public:
    /**
     * @brief Constructs a Position object.
     * @param option The options contract associated with the position.
     * @param quantity The number of options contracts in the position.
     */
    Position(const Option& option, int quantity);

    /**
     * @brief Gets the options contract associated with the position.
     * @return The options contract.
     */
    const Option& get_option() const;

    /**
     * @brief Gets the number of options contracts in the position.
     * @return The quantity.
     */
    int get_quantity() const;

private:
    Option option; /**< The options contract */
    int quantity;  /**< The number of options contracts */
};

}  // namespace thales

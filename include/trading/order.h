// SPDX-License-Identifier: MIT

#pragma once

#include <string>
#include "option.h"

namespace thales {

/**
 * @class Order
 * @brief Represents an order for an options contract.
 */
class Order {
public:
    /**
     * @brief Constructs an Order object.
     * @param action The action of the order (e.g., "Buy" or "Sell").
     * @param option The options contract associated with the order.
     * @param quantity The number of options contracts in the order.
     * @param timestamp The timestamp of the order.
     */
    Order(const std::string& action, const Option& option, int quantity, const std::string& timestamp);

    /**
     * @brief Gets the action of the order.
     * @return The action.
     */
    const std::string& get_action() const;

    /**
     * @brief Gets the options contract associated with the order.
     * @return The options contract.
     */
    const Option& get_option() const;

    /**
     * @brief Gets the number of options contracts in the order.
     * @return The quantity.
     */
    int get_quantity() const;

    /**
     * @brief Gets the timestamp of the order.
     * @return The timestamp.
     */
    const std::string& get_timestamp() const;

private:
    std::string action; /**< The action of the order */
    Option option;      /**< The options contract */
    int quantity;       /**< The number of options contracts */
    std::string timestamp; /**< The timestamp of the order */
};

}  // namespace thales

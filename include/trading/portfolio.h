// SPDX-License-Identifier: MIT

#pragma once

#include <vector>
#include "position.h"

namespace thales {

/**
 * @class Portfolio
 * @brief Represents a portfolio of options positions.
 */
class Portfolio {
public:
    /**
     * @brief Constructs a Portfolio object.
     * @param net_liquidity The net liquidity of the portfolio.
     * @param positions The positions held in the portfolio.
     */
    Portfolio(double net_liquidity, const std::vector<Position>& positions);

    /**
     * @brief Gets the net liquidity of the portfolio.
     * @return The net liquidity.
     */
    double get_net_liquidity() const;

    /**
     * @brief Gets the positions held in the portfolio.
     * @return The positions.
     */
    const std::vector<Position>& get_positions() const;

private:
    double net_liquidity;       /**< The net liquidity of the portfolio */
    std::vector<Position> positions; /**< The positions held in the portfolio */
};

}  // namespace thales

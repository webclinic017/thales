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

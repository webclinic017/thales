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

#include <vector>

#include "gtest/gtest.h"
#include "trading/portfolio.h"
#include "trading/position.h"

namespace thales {

TEST(PortfolioTest, Construction) {
    std::vector<Position> positions = {
        Position("AAPL", "Call", 150.0, "2024-12-15", 10, 5.0),
        Position("TSLA", "Put", 700.0, "2024-12-15", 5, 10.0)};
    Portfolio portfolio(10000.0, positions);

    EXPECT_EQ(portfolio.get_net_liquidity(), 10000.0);
    ASSERT_EQ(portfolio.get_positions().size(), positions.size());
    EXPECT_EQ(portfolio.get_positions()[0].get_symbol(), "AAPL");
    EXPECT_EQ(portfolio.get_positions()[1].get_symbol(), "TSLA");
}

TEST(PortfolioTest, GetValue) {
    std::vector<Position> positions = {
        Position("AAPL", "Call", 150.0, "2024-12-15", 10, 5.0),
        Position("TSLA", "Put", 700.0, "2024-12-15", 5, 10.0)};
    Portfolio portfolio(10000.0, positions);

    EXPECT_EQ(portfolio.get_net_liquidity(), 10000.0);
}

TEST(PortfolioTest, GetPositions) {
    std::vector<Position> positions = {
        Position("AAPL", "Call", 150.0, "2024-12-15", 10, 5.0),
        Position("TSLA", "Put", 700.0, "2024-12-15", 5, 10.0)};
    Portfolio portfolio(10000.0, positions);

    ASSERT_EQ(portfolio.get_positions().size(), 2);
    EXPECT_EQ(portfolio.get_positions()[0].get_symbol(), "AAPL");
    EXPECT_EQ(portfolio.get_positions()[0].get_option_type(), "Call");
    EXPECT_EQ(portfolio.get_positions()[0].get_strike_price(), 150.0);
    EXPECT_EQ(portfolio.get_positions()[0].get_expiration_date(), "2024-12-15");
    EXPECT_EQ(portfolio.get_positions()[0].get_quantity(), 10);
    EXPECT_EQ(portfolio.get_positions()[0].get_premium(), 5.0);

    EXPECT_EQ(portfolio.get_positions()[1].get_symbol(), "TSLA");
    EXPECT_EQ(portfolio.get_positions()[1].get_option_type(), "Put");
    EXPECT_EQ(portfolio.get_positions()[1].get_strike_price(), 700.0);
    EXPECT_EQ(portfolio.get_positions()[1].get_expiration_date(), "2024-12-15");
    EXPECT_EQ(portfolio.get_positions()[1].get_quantity(), 5);
    EXPECT_EQ(portfolio.get_positions()[1].get_premium(), 10.0);
}

}  // namespace thales

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

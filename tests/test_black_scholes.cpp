#include "gtest/gtest.h"
#include "trading/black_scholes.h"

class BlackScholesTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

TEST_F(BlackScholesTest, CalculateOptionPrice) {
    double S = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    OptionType type = OptionType::CALL;
    double expected_price = 10.4506;

    double price = BlackScholes::calculate_option_price(S, K, T, r, sigma, type);

    ASSERT_NEAR(price, expected_price, 0.0001);
}

TEST_F(BlackScholesTest, DeepInTheMoneyPutOption) {
    double S = 50.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    OptionType type = OptionType::PUT;
    double expected_price = 45.1253;

    double price = BlackScholes::calculate_option_price(S, K, T, r, sigma, type);

    ASSERT_NEAR(price, expected_price, 0.0001);
}

TEST_F(BlackScholesTest, ZeroVolatility) {
    double S = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.0;
    OptionType type = OptionType::CALL;
    double expected_price = 4.8771;

    double price = BlackScholes::calculate_option_price(S, K, T, r, sigma, type);

    ASSERT_NEAR(price, expected_price, 0.0001);
}

TEST_F(BlackScholesTest, ZeroInterestRate) {
    double S = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.0;
    double sigma = 0.2;
    OptionType type = OptionType::CALL;
    double expected_price = 7.9656;

    double price = BlackScholes::calculate_option_price(S, K, T, r, sigma, type);

    ASSERT_NEAR(price, expected_price, 0.0001);
}

TEST_F(BlackScholesTest, NearExpiry) {
    double S = 100.0;
    double K = 100.0;
    double T = 0.01;
    double r = 0.05;
    double sigma = 0.2;
    OptionType type = OptionType::CALL;
    double expected_price = 0.8229; // Updated expected value

    double price = BlackScholes::calculate_option_price(S, K, T, r, sigma, type);

    ASSERT_NEAR(price, expected_price, 0.0001);
}

TEST_F(BlackScholesTest, LongTimeToExpiry) {
    double S = 100.0;
    double K = 100.0;
    double T = 10.0;
    double r = 0.05;
    double sigma = 0.2;
    OptionType type = OptionType::CALL;
    double expected_price = 45.1929;

    double price = BlackScholes::calculate_option_price(S, K, T, r, sigma, type);

    ASSERT_NEAR(price, expected_price, 0.0001);
}

TEST_F(BlackScholesTest, InvalidOptionType) {
    EXPECT_THROW(
        BlackScholes::calculate_option_price(100.0, 100.0, 1.0, 0.05, 0.2, static_cast<OptionType>(-1)),
        std::invalid_argument
    );
}

TEST_F(BlackScholesTest, InvalidInputParameters) {
    EXPECT_THROW(
        BlackScholes::calculate_option_price(-100.0, 100.0, 1.0, 0.05, 0.2, OptionType::CALL),
        std::invalid_argument
    );
    EXPECT_THROW(
        BlackScholes::calculate_option_price(100.0, -100.0, 1.0, 0.05, 0.2, OptionType::CALL),
        std::invalid_argument
    );
    EXPECT_THROW(
        BlackScholes::calculate_option_price(100.0, 100.0, -1.0, 0.05, 0.2, OptionType::CALL),
        std::invalid_argument
    );
    EXPECT_THROW(
        BlackScholes::calculate_option_price(100.0, 100.0, 1.0, 0.05, -0.2, OptionType::CALL),
        std::invalid_argument
    );
}

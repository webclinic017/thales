#include <benchmark/benchmark.h>

#include "trading/portfolio.h"
#include "trading/position.h"

static void BM_PortfolioCreation(benchmark::State& state) {
    // Constants
    const double AAPL_CALL_STRIKE = 150.0;
    const double TSLA_PUT_STRIKE = 700.0;
    const double AAPL_CALL_PREMIUM = 5.0;
    const double TSLA_PUT_PREMIUM = 10.0;
    const int AAPL_CALL_QUANTITY = 10;
    const int TSLA_PUT_QUANTITY = 5;
    const double INITIAL_PORTFOLIO_NET_LIQ = 10000.0;

    for (auto state_iter : state) {
        std::vector<thales::Position> positions = {
            thales::Position("AAPL", "Call", AAPL_CALL_STRIKE, "2024-12-15",
                             AAPL_CALL_QUANTITY, AAPL_CALL_PREMIUM),
            thales::Position("TSLA", "Put", TSLA_PUT_STRIKE, "2024-12-15",
                             TSLA_PUT_QUANTITY, TSLA_PUT_PREMIUM)};
        thales::Portfolio portfolio(INITIAL_PORTFOLIO_NET_LIQ, positions);
    }
}
BENCHMARK(BM_PortfolioCreation);

static void BM_PortfolioNetLiquidityCalculation(benchmark::State& state) {
    // Constants
    const double AAPL_CALL_STRIKE = 150.0;
    const double TSLA_PUT_STRIKE = 700.0;
    const double AAPL_CALL_PREMIUM = 5.0;
    const double TSLA_PUT_PREMIUM = 10.0;
    const int AAPL_CALL_QUANTITY = 10;
    const int TSLA_PUT_QUANTITY = 5;
    const double INITIAL_PORTFOLIO_NET_LIQ = 10000.0;

    for (auto state_iter : state) {
        std::vector<thales::Position> positions = {
            thales::Position("AAPL", "Call", AAPL_CALL_STRIKE, "2024-12-15",
                             AAPL_CALL_QUANTITY, AAPL_CALL_PREMIUM),
            thales::Position("TSLA", "Put", TSLA_PUT_STRIKE, "2024-12-15",
                             TSLA_PUT_QUANTITY, TSLA_PUT_PREMIUM)};
        thales::Portfolio portfolio(INITIAL_PORTFOLIO_NET_LIQ, positions);
        benchmark::DoNotOptimize(portfolio.get_net_liquidity());
    }
}
BENCHMARK(BM_PortfolioNetLiquidityCalculation);

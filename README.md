# Thales: an Algorithmic Options Trading Bot

![build](https://github.com/cm-jones/thales/actions/workflows/ci.yml/badge.svg)
[![codecov](https://codecov.io/gh/cm-jones/thales/branch/main/graph/badge.svg?token=fc9ee083-78b6-4e43-bf23-bfa85832df85)](https://codecov.io/gh/cm-jones/thales)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Description

Thales (*THAY-leez*) is a high-frequency, algorithmic trading bot designed for trading options contracts, named after the Greek philosopher [Thales of Miletus](https://en.wikipedia.org/wiki/Thales_of_Miletus), who is credited with the first recorded use of an options contract.

The bot uses the Black-Scholes formula and various statistical models to identify options that are "mispriced" by the market. For example, if the bot thinks a call or put is currently undervalued, it will attempt to buy that call or put.

## Requirements

- C++17 compiler (GCC v7.1+ or Clang v5.0+)
- CMake v3.12+
- Google Test v1.8.0+ for unit testing
- Google Benchmark v1.3.0+ for benchmarking
- libcurl v7.50.0+ for HTTP requests
- API key from Polygon.io for real-time options data

## Usage

To start the bot, simply execute the following command inside the `build` directory:

```sh
./thales
```

By default, thales will run in paper trading mode using the Polygon.io API for simulating trades and tracking the paper trading portfolio. You can configure various settings, such as the trading strategy, risk management parameters, and data sources, by modifying the appropriate configuration files.

## Build

1. Clone the repository:
   ```sh
   git clone https://github.com/cm-jones/thales.git
   cd thales
   ```

2. Configure the build system:
   ```sh
   cmake -S . -B build
   ```

3. Build the project:
   ```sh
   cmake --build build
   ```

## Testing

Thales uses [Google Test](https://github.com/google/googletest) for unit testing. To run the unit tests, execute the following command inside the `build` directory:

```sh
ctest
```

This will run all the registered unit tests and display the results.

## Benchmarking

Thales uses [Google Benchmark](https://github.com/google/benchmark) for benchmarking. To run the benchmarks, follow these steps:

1. Build the benchmarks (if not already built):
   ```
   cmake --build build --target thales_benchmarks
   ```

2. Run the benchmarks:
   ```
   cd build
   make thales_benchmarks
   ./thales_benchmarks
   ```

This will execute all the registered benchmarks and display the results.

## Configuration

Thales can be configured through various configuration files inside the `config` directory. Here's a brief overview of the available configuration options:

- `polygon_credentials.cfg` (required): Contains the Polygon.io API key for accessing real-time and historical options data.
- `trading_strategy.cfg`: Defines the parameters and settings for the trading strategy.
- `risk_management.cfg`: Specifies risk management rules and thresholds.
- `data_sources.cfg`: Configures the data sources for historical and real-time market data.

Refer to the individual configuration files and the project documentation for more details on configuring the trading bot.

## Contributing

If you find any issues or have suggestions for improvements, feel free to [open an issue](https://github.com/cm-jones/thales/issues/new) or submit a [pull request](https://github.com/thales/libdsc/compare).

## License

This project is licensed under the [MIT License](LICENSE).

# thales: an algorithmic options trading bot

![build](https://github.com/cm-jones/thales/actions/workflows/ci.yml/badge.svg)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)


Thales is an algorithmic trading bot designed for options trading, named after the Greek philosopher Thales of Miletus, who is credited with the first recorded use of an options contract.

## Getting Started

These instructions will guide you through building and running the Thales bot, as well as executing the unit tests and benchmarks.

### Prerequisites

- C++17 compiler (e.g., GCC, Clang)
- CMake (version 3.12 or higher)
- Google Test (for unit testing)
- Google Benchmark (for benchmarking)
- Polygon.io C++ client library

### Building

1. Clone the repository:
   ```
   git clone https://github.com/cm-jones/thales.git
   cd thales
   ```

2. Configure the build system:
   ```
   cmake -S . -B build
   ```

3. Build the project:
   ```
   cmake --build build
   ```

### Running Unit Tests

Thales uses Google Test for unit testing. To run the unit tests, execute the following command:

```
cd build
ctest
```

This will run all the registered unit tests and display the results.

### Running Benchmarks

Thales uses Google Benchmark for benchmarking various components of the trading bot. To run the benchmarks, follow these steps:

1. Build the benchmarks (if not already built):
   ```
   cmake --build build --target run_benchmarks
   ```

2. Run the benchmarks:
   ```
   cd build
   make run_benchmarks
   ```

This will execute all the registered benchmarks and display the results.

### Running the Trading Bot

To run the Thales trading bot, execute the following command from the `build` directory:

```
./thales
```

By default, the bot will run in paper trading mode using the Polygon.io API for simulating trades and tracking the paper trading portfolio. You can configure various settings, such as the trading strategy, risk management parameters, and data sources, by modifying the appropriate configuration files.

## Configuration

The Thales trading bot can be configured through various configuration files located in the `config` directory. Here's a brief overview of the available configuration options:

- `polygon_credentials.cfg`: Contains the Polygon.io API key for accessing real-time and historical data.
- `trading_strategy.cfg`: Defines the parameters and settings for the trading strategy.
- `risk_management.cfg`: Specifies risk management rules and thresholds.
- `data_sources.cfg`: Configures the data sources for historical and real-time market data.

Please refer to the individual configuration files and the project documentation for more details on configuring the trading bot.

## Contributing

Contributions to the Thales project are welcome! If you encounter any issues or have suggestions for improvements, please open an issue or submit a pull request on the project's GitHub repository.

## License

This project is licensed under the [MIT License](LICENSE).

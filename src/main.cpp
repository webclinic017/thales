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

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

#include "config/config.h"
#include "trading/portfolio.h"
#include "utils/http_client.h"

using namespace thales;

int main() {
    std::string api_key;

    try {
        api_key = Config::get_api_key();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    thales::HttpClient http_client;
    std::string url =
        "https://api.polygon.io/v2/aggs/ticker/AAPL/range/1/day/2023-01-01/"
        "2023-01-31?apiKey=" +
        api_key;
    std::string result;

    try {
        result = http_client.get(url);
    } catch (const std::exception& e) {
        std::cerr << "HTTP request failed: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    while (true) {
        Portfolio portfolio = fetch_portfolio();
        display_portfolio(portfolio);

        std::vector<Order> orders = fetch_orders();
        display_orders(orders);

        // Sleep for 1 second before updating
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Clear the screen (platform-dependent)
#if defined(_WIN32) || defined(_WIN64)
        std::system("cls");
#else
        std::system("clear");
#endif
    }

    return EXIT_SUCCESS;
}

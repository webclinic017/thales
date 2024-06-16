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

#include <iostream>

#include "config/config.h"
#include "utils/http_client.h"

int main() {
    std::cout << "Thales Options Trading Bot" << std::endl;

    std::string api_key = thales::Config::get_api_key();
    if (api_key.empty()) {
        std::cerr << "API key not found in the configuration file."
                  << std::endl;
        return 1;
    }

    thales::HttpClient http_client;
    std::string url =
        "https://api.polygon.io/v2/aggs/ticker/AAPL/range/1/day/2023-01-01/"
        "2023-01-31?api_key=" +
        api_key;

    std::string response = http_client.get(url);
    std::cout << "Response: " << response << std::endl;

    return 0;
}

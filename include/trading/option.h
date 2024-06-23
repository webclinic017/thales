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

#include <cstdint>  // For std::uint8_t
#include <string>

namespace thales {

/**
 * @class Option
 * @brief Represents an options contract.
 */
class Option {
   public:
    /**
     * @enum OptionType
     * @brief Types of options contracts.
     */
    enum class OptionType : std::uint8_t {
        CALL, /**< Call option */
        PUT   /**< Put option */
    };

    /**
     * @brief Constructs an Option object.
     * @param symbol The ticker symbol of the underlying asset.
     * @param type The type of the option (CALL or PUT).
     * @param strike_price The strike price of the option.
     * @param expiration_date The expiration date of the option.
     * @param premium The premium of the option.
     */
    Option(const std::string& symbol, OptionType type, double strike_price,
           const std::string& expiration_date, double premium);

    /**
     * @brief Gets the ticker symbol of the underlying asset.
     * @return The ticker symbol.
     */
    const std::string& get_symbol() const;

    /**
     * @brief Gets the type of the option.
     * @return The option type.
     */
    OptionType get_type() const;

    /**
     * @brief Gets the strike price of the option.
     * @return The strike price.
     */
    double get_strike_price() const;

    /**
     * @brief Gets the expiration date of the option.
     * @return The expiration date.
     */
    const std::string& get_expiration_date() const;

    /**
     * @brief Gets the premium of the option.
     * @return The premium.
     */
    double get_premium() const;

   private:
    std::string symbol;  /**< The ticker symbol of the underlying asset */
    OptionType type;     /**< The type of the option */
    double strike_price; /**< The strike price of the option */
    std::string expiration_date; /**< The expiration date of the option */
    double premium;              /**< The premium of the option */
};

}  // namespace thales

module;

export module qubiz.aoc:utils;

import std;
import qubiz.core;
import qubiz.status;

export namespace qubiz::aoc::utils
{
    constexpr auto parse_int(const std::string_view input) -> u64
    {
        u64 val = 0;
        for (const char i : input)
        {
            val = val * 10 + (i - '0');
        }
        return val;
    }

    constexpr auto pow(const u64 base, const u64 exponent) -> u64
    {
        u64 res = 1;
        for (u64 i = 0; i < exponent; ++i)
        {
            res *= base;
        }
        return res;
    }

    constexpr auto count_digits(const u64 n) -> u64
    {
        return std::floor(std::log10(n) + 1);
    }

}

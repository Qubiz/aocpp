module;

export module qubiz.aoc:types;

import std;
export import qubiz.core;
export import qubiz.status;

export namespace qubiz::aoc
{
    struct PuzzleResult
    {
        Result<i64> part1{};
        Result<i64> part2{};
    };

    struct PuzzleConfig
    {
        std::chrono::year year;
        std::chrono::day day;
        std::string_view input;
    };
}

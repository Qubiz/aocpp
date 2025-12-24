module;

export module qubiz.aoc:y2025.day2;

import std;
import qubiz.core;
import qubiz.status;
import fmt;

export import :types;

export namespace qubiz::aoc::y2025::day2
{
    constexpr auto part1() -> Result<i64>
    {
        return err(error_code::unimplemented);
    }

    // static_assert(part1().value() == 3);

    constexpr auto part2() -> Result<i64>
    {
        return err(error_code::unimplemented);
    }

    // static_assert(part2().value() == 6);

    auto solve(const std::string_view input) -> Result<PuzzleResult>
    {
        return ok(PuzzleResult(part1(), part2()));
    }
}

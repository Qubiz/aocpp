module;

export module qubiz.aoc;

import std;
import qubiz.core;
import qubiz.status;

export import :types;
export import :puzzle_input_producer;
export import :y2025.day1;

export namespace qubiz::aoc
{
    auto solve(const PuzzleConfig& config) -> Result<PuzzleResult>
    {
        using namespace std::chrono_literals;
        if (config.year == 2025y)
        {
            if (config.day == 1d)
            {
                return y2025::day1::solve(config.input);
            }
        }

        return err(error_code::not_found);
    }
}

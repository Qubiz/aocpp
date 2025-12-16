module;

#include <chrono>

export module qubiz.aoc;

import qubiz.core;
import qubiz.status;

export import :y2025;
export import :types;
export import :puzzle_input_producer;

export namespace qubiz::aoc
{
    auto solve(const PuzzleConfig& config) -> Result<PuzzleResult>
    {
        using namespace std::chrono_literals;
        if (config.year == 2025y)
        {
            return y2025::solve(config);
        }

        return err(error_code::not_found);
    }
}

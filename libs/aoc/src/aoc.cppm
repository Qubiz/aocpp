module;

export module qubiz.aoc;

export import std;
export import qubiz.core;
export import qubiz.status;
export import :puzzle_input_producer;
export import :types;
export import :utils;
export import :y2025.day1;
export import :y2025.day2;

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

            if (config.day == 2d)
            {
                return y2025::day2::solve(config.input);
            }
        }

        return err(error_code::not_found);
    }
}
// Forced rebuild
module;

#include <chrono>
#include <ranges>
#include <string_view>
#include <string>

#include <qubiz/status/try.hpp>

export module qubiz.aoc:y2025;

import qubiz.core;
import qubiz.status;
import :puzzle_input_producer;
import :types;

namespace qubiz::aoc::y2025
{
    using namespace std::chrono_literals;

    constexpr static i64 STARTING_POSITION = 50;
    constexpr static i64 NUM_POSITIONS = 100;

    class Day1
    {
        static auto part1(std::string_view puzzle_input) -> Result<i64>
        {
            usize counted_zeroes{0};
            i64 position = STARTING_POSITION;
            for (const auto line : std::views::split(puzzle_input, '\n'))
            {
                const auto l = std::string_view{line};

                i64 rotate_amount{0};
                if (auto [ptr, ec] = std::from_chars(l.begin() + 1, l.end(), rotate_amount); ec != std::errc())
                {
                    return err(error_code::invalid_argument);
                }

                if (l.starts_with('L'))
                {
                    position = position - rotate_amount;
                }
                else if (l.starts_with('R'))
                {
                    position = position + rotate_amount;
                }

                /// If we rotated to the left and passed 0 (so a negative number),
                /// we need to rotate back until the value is back into the valid
                /// range.
                while (position < 0)
                {
                    position += NUM_POSITIONS;
                }

                /// If we rotated to the right and passed max (so a negative number),
                /// we need to rotate back until the value is back into the valid
                /// range.
                while (position >= NUM_POSITIONS)
                {
                    position -= NUM_POSITIONS;
                }

                if (position == 0)
                {
                    counted_zeroes++;
                }
            }
            return ok(counted_zeroes);
        }

        static auto part2(std::string_view puzzle_input) -> Result<i64>
        {
            return err(error_code::unimplemented);
        }

    public:
        static auto solve(const std::string_view input) -> Result<PuzzleResult>
        {
            return ok(PuzzleResult(part1(input), part2(input)));
        }
    };

    export auto solve(const PuzzleConfig& config) -> Result<PuzzleResult>
    {
        if (config.day == 1d)
        {
            return Day1::solve(config.input);
        }

        return err(error_code::not_found);
    }
}

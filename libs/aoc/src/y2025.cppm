module;

#include <chrono>
#include <ranges>
#include <string_view>
#include <string>

#include "qubiz/status/try.hpp"

export module qubiz.aoc:y2025;

import qubiz.core;
import qubiz.status;
import :puzzle_input_producer;

export namespace qubiz::aoc::y2025 {
    auto run(std::chrono::day day,
             const PuzzleInputProducer &producer = DefaultPuzzleInputProducer::fetch) -> Result<i64>;
}

namespace qubiz::aoc::y2025 {
    using namespace std::chrono_literals;

    auto fetch_input(std::chrono::day day) -> Result<std::string> {
        return R"(L68
L30
R48
L5
R60
L55
L1
L99
R14
L82)";
    }

    auto day1(const PuzzleInputProducer &producer = DefaultPuzzleInputProducer::fetch) -> Result<i64> {
        const auto input = QUBIZ_TRY(producer(2025y, 1d));

        constexpr static i64 STARTING_POSITION = 50;
        constexpr static i64 NUM_POSITIONS = 100;

        usize counted_zeroes{0};
        i64 position = STARTING_POSITION;
        for (const auto line: std::views::split(input, '\n')) {
            const auto l = std::string_view{line};

            i64 rotate_amount{0};
            if (auto [ptr, ec] = std::from_chars(l.begin() + 1, l.end(), rotate_amount); ec != std::errc()) {
            }

            if (l.starts_with('L')) {
                position = position - rotate_amount;
            } else if (l.starts_with('R')) {
                position = position + rotate_amount;
            }

            /// If we rotated to the left and passed 0 (so a negative number),
            /// we need to rotate back until the value is back into the valid
            /// range.
            while (position < 0) {
                position += NUM_POSITIONS;
            }

            /// If we rotated to the right and passed max (so a negative number),
            /// we need to rotate back until the value is back into the valid
            /// range.
            while (position >= NUM_POSITIONS) {
                position -= NUM_POSITIONS;
            }

            if (position == 0) {
                counted_zeroes++;
            }
        }

        return ok(counted_zeroes);
    }

    auto run(const std::chrono::day day,
             const PuzzleInputProducer &producer) -> Result<i64> {

        if (day == 1d) {
            return day1(producer);
        }

        return err(error_code::not_found);
    }
}

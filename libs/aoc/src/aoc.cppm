module;

#include <chrono>

export module qubiz.aoc;

import qubiz.core;
import qubiz.status;

export import :y2025;
export import :puzzle_input_producer;

export namespace qubiz::aoc {
    auto run(std::chrono::year year,
             std::chrono::day day,
             const PuzzleInputProducer &puzzle_input_producer = DefaultPuzzleInputProducer::fetch) -> Result<i64>;
}

namespace qubiz::aoc {
    using namespace std::chrono_literals;

    auto run(const std::chrono::year year,
             const std::chrono::day day,
             const PuzzleInputProducer &puzzle_input_producer
    ) -> Result<i64> {
        if (year == 2025y) {
            return y2025::run(day, puzzle_input_producer);
        }

        return err(error_code::not_found);
    }
}

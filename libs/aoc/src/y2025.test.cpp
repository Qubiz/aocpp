#include <catch2/catch_test_macros.hpp>

import std;
import qubiz.aoc;
import qubiz.core;
import qubiz.status;

using namespace std::chrono_literals;

namespace qubiz {
    struct TestInputProducer {
        static auto fetch(const std::chrono::year y, const std::chrono::day d) -> Result<std::string> {
            if (y != 2025y) {
                return err(error_code::invalid_argument);
            }


            if (d == 1d) {
                return ok(
                    R"(L68
L30
R48
L5
R60
L55
L1
L99
R14
L82)"
                );
            }

            return err(error_code::not_found);
        }
    };
}

TEST_CASE("Y2025 - D1") {
    auto input_res = qubiz::TestInputProducer::fetch(2025y, 1d);
    REQUIRE(input_res.has_value());

    const qubiz::aoc::PuzzleConfig config{
        .year = 2025y,
        .day = 1d,
        .input = *input_res
    };

    const auto result = qubiz::aoc::solve(config);
    REQUIRE(result.has_value());
    REQUIRE(result->part1.has_value());
    REQUIRE(*result->part1 == 3);
    REQUIRE(result->part2.has_value());
    REQUIRE(*result->part2 == 6);
}

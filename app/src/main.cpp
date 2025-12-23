#include <cstdio>
#include <fmt/format.h>

import std;
import qubiz.status;
import qubiz.aoc;

#include <qubiz/status/try.hpp>

using namespace qubiz;
using namespace std::chrono_literals;

namespace qubiz
{
    auto env(const char* name) -> Result<const char*>
    {
        if (const auto result = std::getenv(name); !result)
        {
            fmt::println(stderr, "Env variable '{}' does not exist", name);
            return err(error_code::not_found);
        }
        else
        {
            return ok(result);
        }
    }

    auto result_display(const aoc::PuzzleResult& result)
    {
        const auto& [part1, part2] = result;
        if (part1)
        {
            fmt::println("- Part 1: {}", part1.value());
        }
        else
        {
            fmt::println(stderr, "- Part 1: {}", as_string(part1.error()));
        }

        if (part2)
        {
            fmt::println("- Part 2: {}", part2.value());
        }
        else
        {
            fmt::println(stderr, "- Part 2: {}", as_string(part2.error()));
        }
    }

    auto run() -> Status
    {
        constexpr static auto year = 2025y;
        constexpr static auto day = 1d;

        fmt::println("Solving puzzle for {}, day {}:", static_cast<int>(year), static_cast<unsigned>(day));

        // Use the default puzzle input producer to fetch the input directly from AOC.
        aoc::DefaultPuzzleInputProducer producer(QUBIZ_TRY(env("AOC_SESSION_TOKEN")));

        const aoc::PuzzleConfig config{
            .year = year,
            .day = day,
            .input = QUBIZ_TRY(producer.fetch(year, day))
        };

        result_display(QUBIZ_TRY(aoc::solve(config)));

        return ok();
    }
}

int main()
{
    if (auto res = run(); !res)
    {
        fmt::println(stderr, "Failure: {}", as_string(res.error()));
        return 1;
    }
    return 0;
}

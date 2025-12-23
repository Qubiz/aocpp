module;

#include <cstdio>
#include <cpr/cpr.h>
#include <qubiz/status/try.hpp>

export module qubiz.aoc:puzzle_input_producer;

import std;
import fmt;
import qubiz.core;
import qubiz.status;
import :types;

export namespace qubiz::aoc
{
    using PuzzleInputProducer = std::function<Result<std::string>(std::chrono::year, std::chrono::day)>;

    class DefaultPuzzleInputProducer
    {
        const char* session_token_{};

    public:
        explicit DefaultPuzzleInputProducer(const char* session_token) : session_token_{session_token}
        {
        }

        auto fetch(const std::chrono::year y, const std::chrono::day d) -> Result<std::string>
        {
            const auto formatted_url =
                fmt::format("https://adventofcode.com/{}/day/{}/input",
                            static_cast<int>(y), static_cast<unsigned>(d));

            const cpr::Response r = cpr::Get(
                cpr::Url{formatted_url},
                cpr::Header{{"Cookie", fmt::format("session={}", session_token_)}});

            if (r.status_code != 200)
            {
                fmt::println(stderr, "Failed to fetch input: {}", r.status_code);
                return err(error_code::internal);
            }
            return ok(r.text);
        }
    };
} // namespace qubiz::aoc

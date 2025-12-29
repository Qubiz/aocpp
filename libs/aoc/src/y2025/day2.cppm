export module qubiz.aoc:y2025.day2;

export import std;
export import qubiz.core;
export import qubiz.status;
export import :types;
import :utils;
import fmt;

export namespace qubiz::aoc::y2025::day2
{
    auto solve(std::string_view input) -> Result<PuzzleResult>;
}

namespace qubiz::aoc::y2025::day2
{
    constexpr std::string_view EXAMPLE_INPUT =
        R"(11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124)";

    struct IdExtent
    {
        u64 start;
        u64 end;
    };

    template <typename T>
    concept IdExtentRange = std::ranges::input_range<T> &&
        std::same_as<std::ranges::range_value_t<T>, IdExtent>;

    constexpr auto parse_id_extent(std::string_view input) -> IdExtent
    {
        if (input.ends_with('\n'))
        {
            input.remove_suffix(1);
        }

        const auto id_range = std::string_view(input); // 11-22
        const auto sep_index = id_range.find('-');
        const auto id_range_start = id_range.substr(0, sep_index);
        const auto id_range_end = id_range.substr(sep_index + 1);
        return IdExtent{
            .start = utils::parse_int(id_range_start),
            .end = utils::parse_int(id_range_end),
        };
    }

    constexpr bool is_valid_id(u64 id)
    {
        if (id == 0) return true;
        const auto num_digits = utils::count_digits(id);
        if (num_digits % 2 != 0) return true;

        u64 right_half = 0;
        for (u64 i = 0; i < num_digits / 2; ++i)
        {
            // Get the right most digit
            const u64 right_most_digit = id % 10;
            const u64 multiplier = utils::pow(10, i);
            right_half += multiplier * right_most_digit;

            // Remove the right most digit
            id /= 10;
        }

        return id != right_half;
    }
    //
    // // static_assert(1 / 10 == 0);
    // // static_assert(is_valid_id(0));
    // // static_assert(!is_valid_id(11));
    // // static_assert(is_valid_id(12));
    // // static_assert(!is_valid_id(22));
    // // static_assert(!is_valid_id(1010));
    // // static_assert(!is_valid_id(1188511885));

    constexpr auto part1(IdExtentRange auto&& extents) -> Result<u64>
    {
        u64 sum = {};
        for (const IdExtent& extent : extents)
        {
            for (auto id = extent.start; id <= extent.end; ++id)
            {
                if (!is_valid_id(id))
                {
                    sum += id;
                }
            }
        }
        return ok(sum);
    }

    // static_assert(part1().value() == 3);

    constexpr auto part2() -> Result<u64>
    {
        return err(error_code::unimplemented);
    }

    // static_assert(part2().value() == 6);

    // static_assert(part1(parse_input(EXAMPLE_INPUT)) == 1227775554);

    auto solve(const std::string_view input) -> Result<PuzzleResult>
    {
        auto extents = input
            | std::views::split(',')
            | std::views::transform([](const auto split)
            {
                return parse_id_extent(std::string_view(split));
            });

        return ok(PuzzleResult(part1(extents), part2()));
    }
}
module;

export module qubiz.aoc:y2025.day1;

import std;
import qubiz.core;
import qubiz.status;
import fmt;

export import :types;

export namespace qubiz::aoc::y2025::day1
{
    using namespace std::chrono_literals;

    constexpr i64 STARTING_POSITION = 50;
    constexpr i64 NUM_POSITIONS = 100;

    enum class Direction
    {
        LEFT, RIGHT
    };

    struct DialState
    {
        i64 position{STARTING_POSITION};
        i64 exact_zeroes{0};
        i64 passed_zeroes{0};
    };

    constexpr auto parse_int(const std::string_view input) -> i64
    {
        i64 val = 0;
        for (const char i : input)
        {
            val = val * 10 + (i - '0');
        }
        return val;
    }

    struct RotateAction
    {
        constexpr explicit RotateAction(const std::string_view input)
            : amount(parse_int(input.substr(1))),
              direction((input[0] == 'L') ? Direction::LEFT : Direction::RIGHT)
        {
        }

        i64 amount;
        Direction direction;
    };

    constexpr auto rotate(DialState state, RotateAction action) -> DialState
    {
        while (action.amount != 0)
        {
            action.amount -= 1;
            if (action.direction == Direction::LEFT)
            {
                // Rotating left
                state.position -= 1;
                if (state.position == -1)
                {
                    state.position = 99;
                }
            }
            else
            {
                state.position += 1;
                if (state.position == NUM_POSITIONS)
                {
                    state.position = 0;
                }
            }
            state.exact_zeroes += (state.position == 0 && action.amount == 0);
            state.passed_zeroes += (state.position == 0 && action.amount != 0);
        }

        return state;
    }

    template <typename T>
    concept RotateActionRange = std::ranges::input_range<T> &&
        std::same_as<std::ranges::range_value_t<T>, RotateAction>;

    constexpr auto apply_rotate_actions(DialState state, RotateActionRange auto&& remaining_actions) -> DialState
    {
        for (const RotateAction action : remaining_actions)
        {
            state = rotate(state, action);
        }
        return state;
    }

    constexpr std::array EXAMPLE_INPUT = {
        RotateAction("L68"),
        RotateAction("L30"),
        RotateAction("R48"),
        RotateAction("L5"),
        RotateAction("R60"),
        RotateAction("L55"),
        RotateAction("L1"),
        RotateAction("L99"),
        RotateAction("R14"),
        RotateAction("L82"),
    };

    constexpr auto part1(RotateActionRange auto&& actions) -> Result<i64>
    {
        const DialState final_state = apply_rotate_actions(DialState{}, actions);
        return ok(final_state.exact_zeroes);
    }

    static_assert(part1(EXAMPLE_INPUT).value() == 3);

    constexpr auto part2(RotateActionRange auto&& actions) -> Result<i64>
    {
        const DialState final_state = apply_rotate_actions(DialState{}, actions);
        return ok(final_state.exact_zeroes + final_state.passed_zeroes);
    }

    static_assert(part2(EXAMPLE_INPUT).value() == 6);

    auto solve(const std::string_view input) -> Result<PuzzleResult>
    {
        auto actions = input
            | std::views::split('\n')
            | std::views::filter([](const auto line) -> bool { return !line.empty(); })
            | std::views::transform([](const auto line)
            {
                return RotateAction(std::string_view(line));
            });
        return ok(PuzzleResult(part1(actions), part2(actions)));
    }
}

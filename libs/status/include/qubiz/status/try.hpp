#pragma once

import std;

namespace qubiz::detail
{
    template <typename T, typename E>
    constexpr auto get_expected_value(std::expected<T, E>&& e) noexcept -> T
    {
        if constexpr (std::is_void_v<T>)
        {
            return;
        }
        else
        {
            return std::move(e).value();
        }
    }
}

#if defined(__GNUC__) || defined(__clang__)

#define QUBIZ_TRY(expression)                                            \
    ({                                                                   \
        auto&& _temporary_result = (expression);                         \
        if (!_temporary_result.has_value()) [[unlikely]]                 \
            return qubiz::err(_temporary_result.error());                \
        qubiz::detail::get_expected_value(std::move(_temporary_result));         \
    })

#endif

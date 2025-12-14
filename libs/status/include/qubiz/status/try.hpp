#pragma once

import qubiz.core;

#if defined(__GNUC__) || defined(__clang__)

#define QUBIZ_TRY(expression)                                            \
    ({                                                                   \
        auto&& _temporary_result = (expression);                         \
        if (!_temporary_result.has_value()) [[unlikely]]                 \
            return qubiz::err(_temporary_result.error());                \
        qubiz::get_expected_value(std::move(_temporary_result)); \
    })

#endif

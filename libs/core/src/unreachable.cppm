module;

#include <utility>

export module qubiz.core:unreachable;

export namespace qubiz {
    [[noreturn]] inline void unreachable()
    {
        std::unreachable();
    }
} // namespace robor

module;

export module qubiz.core:unreachable;

import std;

export namespace qubiz {
    [[noreturn]] inline void unreachable()
    {
        std::unreachable();
    }
} // namespace robor

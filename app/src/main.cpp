#include <print>
#include <chrono>

#include <qubiz/status/try.hpp>

import qubiz.status;
import qubiz.aoc;

using namespace qubiz;
using namespace std::chrono_literals;

namespace qubiz {
    auto run() -> Status {
        auto result = QUBIZ_TRY(aoc::run(2025y, 1d));
        std::println("Result: {}", result);
        return ok();
    }
}

int main() {
    if (auto res = run(); !res) {
        std::println(stderr, "Failure: {}", as_string(res.error()));
        return 1;
    }
    return 0;
}

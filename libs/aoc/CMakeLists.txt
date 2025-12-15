add_library(qubiz.aoc)

target_sources(qubiz.aoc
        PUBLIC
        FILE_SET CXX_MODULES
        FILES
        src/aoc.cppm
        src/puzzle_input_producer.cppm
        src/y2025.cppm
)

target_link_libraries(qubiz.aoc
        qubiz.core
        qubiz.status
        cpr::cpr
        fmt::fmt
)

#########
# Tests #
#########
add_executable(qubiz.aoc.test)

target_sources(qubiz.aoc.test
        PRIVATE
        src/y2025.test.cpp
)

target_link_libraries(qubiz.aoc.test
        PRIVATE
        Catch2::Catch2WithMain
        qubiz.aoc
)

catch_discover_tests(qubiz.aoc.test)
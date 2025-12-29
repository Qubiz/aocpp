add_library(qubiz.aoc STATIC)

target_sources(qubiz.aoc
        PUBLIC
        FILE_SET CXX_MODULES
        FILES
        src/aoc.cppm
        src/puzzle_input_producer.cppm
        src/types.cppm
        src/utils.cppm
        src/y2025/day1.cppm
        src/y2025/day2.cppm
)

target_link_libraries(qubiz.aoc
        PUBLIC
        qubiz.core
        qubiz.status
        cpr::cpr
        fmt::fmt
)

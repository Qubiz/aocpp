add_executable(aoc++)

target_sources(aoc++
        PRIVATE
        src/main.cpp
)

target_link_libraries(aoc++
        PRIVATE
        qubiz.aoc
)

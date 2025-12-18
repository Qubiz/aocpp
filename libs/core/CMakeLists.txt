add_library(qubiz.core STATIC)

target_sources(qubiz.core
        PUBLIC
        FILE_SET CXX_MODULES
        FILES
        src/core.cppm
        src/types.cppm
        src/optional.cppm
        src/expected.cppm
        src/unreachable.cppm
)

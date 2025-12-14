add_library(qubiz.status)
target_sources(qubiz.status
        PUBLIC
        FILE_SET CXX_MODULES
        FILES
        src/status.cppm

        INTERFACE
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
        include/qubiz/status/try.hpp
)

target_link_libraries(qubiz.status
        PUBLIC
        qubiz.core
)

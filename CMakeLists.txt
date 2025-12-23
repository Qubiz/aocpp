cmake_minimum_required(VERSION 4.2)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")

project(aoc++ LANGUAGES CXX)

include(cmake/CPM.cmake)

CPMAddPackage(
        URI "gh:fmtlib/fmt#12.1.0"
        OPTIONS "FMT_MODULE ON"
)
CPMAddPackage("gh:catchorg/Catch2@3.11.0")
CPMAddPackage("gh:libcpr/cpr#1.14.1")

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_subdirectory(libs/core)
add_subdirectory(libs/status)
add_subdirectory(libs/aoc)

add_subdirectory(app)

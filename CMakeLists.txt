cmake_minimum_required(VERSION 4.1)

project(aoc++ LANGUAGES CXX)

include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#12.1.0")
CPMAddPackage("gh:catchorg/Catch2@3.11.0")
CPMAddPackage("gh:libcpr/cpr#1.14.1")

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_subdirectory(libs/core)
add_subdirectory(libs/status)
add_subdirectory(libs/aoc)

add_subdirectory(app)

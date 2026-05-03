cmake_minimum_required(VERSION 3.16)

# Compiler (clang++)
set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")

project(Problems LANGUAGES CXX)

# C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json for clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

# Compiler flags for color diagnostics and debug/release builds
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics -fansi-escape-codes")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

# Warnings as errors
add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Weffc++
    -Werror
)

# ------ Boost.UT ------
include(FetchContent)
# Set the base directory for ALL FetchContent downloads, or the default build/_deps/
# set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/include")
FetchContent_Declare(
    boost_ut
    GIT_REPOSITORY https://github.com/boost-ext/ut.git
    GIT_TAG        v2.3.1
    GIT_SHALLOW    TRUE
    # Override the default download location
    # SOURCE_DIR "${CMAKE_SOURCE_DIR}/include/boost-ut"
)
FetchContent_MakeAvailable(boost_ut)

# Add subdirectories
add_subdirectory(Algorithms/CumulativeProduct)
# add_subdirectory(Probabilities/BlackWhiteBall)
# Add more as created

# Tests
enable_testing()
add_subdirectory(tests)
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

# Compiler flags matching your original args
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics -fansi-escape-codes")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

# Warnings (matching your original)
add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Weffc++
    -Werror
)

# Add subdirectories
add_subdirectory(Algorithms/CumulativeProduct)
# add_subdirectory(Probabilities/BlackWhiteBall)
# Add more as created
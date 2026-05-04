This repo contains some problems concerning probabilities, algorithms, data structures and coding.

vscode tested on mac OS.

# Requirements

```bash
brew install llvm
brew install cmake
```

# static checks

## C/C++

> .clang-tidy

# code styles and formatting

## C/C++

> .clang-format

# Build

```bash
cmake -S . -B build
cmake -B build
# or only build tests
cmake --build build --target cpptests
```

# Run & Test

## CMake's test runner
```bash
ctest --test-dir build --output-on-failure
# or
ctest --test-dir build -R cpptests --output-on-failure
```

## compiled test
```bash
build/tests/cpptests
```
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
# or
cmake --build build --target cpptests
```

# Run & Test

```bash
ctest --test-dir build --output-on-failure
# or
build/tests/cpptests
# or
ctest --test-dir build -R cpptests --output-on-failure
```
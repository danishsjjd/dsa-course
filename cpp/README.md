# C++ DSA Course

## Requirements

- CMake 3.16+
- A C++17 compiler (clang++, g++, MSVC)

## Build and run

```sh
# from repo root
mkdir -p build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j

# run tests via CTest
ctest --test-dir build --output-on-failure
```

Tip: Generate compile commands for editor tooling by adding `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON` to the first `cmake` command.

## Notes

- Toggle `-DDSA_WARNINGS_AS_ERRORS=ON` to enforce strict compilation.
- Disable tests with `-DDSA_BUILD_TESTS=OFF` if you only want the library without tests.

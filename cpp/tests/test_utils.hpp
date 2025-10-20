#pragma once

#include <iostream>

namespace test {

// Global failure counter shared across a single test executable.
// C++17 inline variable prevents ODR violations across translation units.
inline int failures = 0;

// Prints a summary and returns an appropriate exit code for main().
inline int exit_with_summary(const char* suite_name = nullptr) {
  if (failures == 0) {
    if (suite_name)
      std::cout << "All tests passed: " << suite_name << "\n";
    else
      std::cout << "All tests passed!\n";
    return 0;
  } else {
    if (suite_name)
      std::cout << failures << " test(s) failed in " << suite_name << ".\n";
    else
      std::cout << failures << " test(s) failed.\n";
    return 1;
  }
}

}  // namespace test

// Lightweight assertion macro.
// Usage: CHECK(expr);
#define CHECK(cond)                               \
  do {                                            \
    if (!(cond)) {                                \
      ++::test::failures;                         \
      std::cerr << __FILE__ << ":" << __LINE__    \
                << ": CHECK failed: " #cond "\n"; \
    }                                             \
  } while (0)

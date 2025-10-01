#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Array.hpp"

static int failures = 0;

#define CHECK(cond)                               \
  do {                                            \
    if (!(cond)) {                                \
      ++failures;                                 \
      std::cerr << __FILE__ << ":" << __LINE__    \
                << ": CHECK failed: " #cond "\n"; \
    }                                             \
  } while (0)

int main() {
  auto numbers = Array(3);

  numbers.insert(10);
  numbers.insert(20);
  numbers.insert(30);
  numbers.insert(40);

  //
  std::stringstream ss;
  ss << numbers;
  CHECK(ss.str() == "10203040");

  //
  CHECK(numbers.indexOf(20) == 1);
  CHECK(numbers.indexOf(50) == -1);

  //
  numbers.removeAt(0);
  ss.str("");
  ss.clear();
  ss << numbers;
  CHECK(ss.str() == "203040");

  //
  numbers.removeAt(0);
  numbers.removeAt(1);
  numbers.removeAt(0);
  ss.str("");
  ss.clear();
  ss << numbers;
  CHECK(ss.str() == "");

  //
  try {
    numbers.removeAt(0);
    CHECK(false);
  } catch (const std::out_of_range& e) {
    CHECK(true);
  }

  //
  numbers.insert(50);
  ss.str("");
  ss.clear();
  ss << numbers;
  CHECK(ss.str() == "50");

  if (failures == 0) {
    std::cout << "All utility function tests passed!" << std::endl;
    return 0;
  } else {
    std::cout << failures << " test(s) failed." << std::endl;
    return 1;
  }
}
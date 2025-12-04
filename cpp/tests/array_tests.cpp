#include <iostream>
#include <sstream>

#include "array.hpp"
#include "test_utils.hpp"

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
  CHECK(numbers.indexof(20) == 1);
  CHECK(numbers.indexof(50) == -1);

  //
  numbers.remove_at(0);
  ss.str("");
  ss.clear();
  ss << numbers;
  CHECK(ss.str() == "203040");

  //
  numbers.remove_at(0);
  numbers.remove_at(1);
  numbers.remove_at(0);
  ss.str("");
  ss.clear();
  ss << numbers;
  CHECK(ss.str() == "");

  //
  try {
    numbers.remove_at(0);
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

  numbers.remove_at(0);

  CHECK(numbers.max_index() == -1);

  numbers.insert(10);
  numbers.insert(20);
  numbers.insert(30);
  numbers.insert(40);
  numbers.insert(20);

  CHECK(numbers.max_index() == 3);
  auto other = Array(3);
  other.insert(10);
  other.insert(20);
  other.insert(30);

  auto intersect = numbers.intersect(other);
  ss.str("");
  ss.clear();
  ss << *intersect;
  CHECK(ss.str() == "10203020");

  delete intersect;

  numbers.remove_at(4);
  numbers.insert_at(0, 0);
  ss.str("");
  ss.clear();
  ss << numbers;

  CHECK(ss.str() == "010203040");

  numbers.reverse();
  ss.str("");
  ss.clear();
  ss << numbers;
  CHECK(ss.str() == "403020100");

  return test::exit_with_summary("array");
}
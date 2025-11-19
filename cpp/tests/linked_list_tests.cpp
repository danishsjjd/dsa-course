#include <iostream>
#include <sstream>

#include "linked_list.hpp"
#include "test_utils.hpp"

int main() {
  // Empty list
  {
    LinkedList list;
    CHECK(list.isEmpty());
    CHECK(list.front() == nullptr);
    CHECK(list.back() == nullptr);
    std::stringstream ss;
    ss << list;
    CHECK(ss.str() == "[]\n");

    // Removing from empty should be no-op
    list.remove_front();
    list.remove_back();
    CHECK(list.isEmpty());
    CHECK(list.front() == nullptr);
    CHECK(list.back() == nullptr);
  }

  // Push back one
  {
    LinkedList list;
    list.push_back(3);
    CHECK(!list.isEmpty());
    CHECK(list.front() && list.front()->value == 3);
    CHECK(list.back() && list.back()->value == 3);
    std::stringstream ss;
    ss << list;
    CHECK(ss.str() == "[3]\n");
    CHECK(list.contains(3));
    CHECK(list.indexof(3) == 0);
    CHECK(!list.contains(99));
    CHECK(list.indexof(99) == -1);
  }

  // Push back then push front, check order and indices
  {
    LinkedList list;
    list.push_back(3);   // [3]
    list.push_back(4);   // [3,4]
    list.push_front(2);  // [2,3,4]

    CHECK(list.front() && list.front()->value == 2);
    CHECK(list.back() && list.back()->value == 4);

    std::stringstream ss;
    ss << list;
    CHECK(ss.str() == "[2, 3, 4]\n");

    CHECK(list.contains(2));
    CHECK(list.contains(3));
    CHECK(list.contains(4));
    CHECK(list.indexof(2) == 0);
    CHECK(list.indexof(3) == 1);
    CHECK(list.indexof(4) == 2);
  }

  // Removals update ends correctly
  {
    LinkedList list;
    list.push_back(3);   // [3]
    list.push_back(4);   // [3,4]
    list.push_front(2);  // [2,3,4]

    list.remove_front();  // [3,4]
    CHECK(list.front() && list.front()->value == 3);
    CHECK(list.back() && list.back()->value == 4);
    {
      std::stringstream ss;
      ss << list;
      CHECK(ss.str() == "[3, 4]\n");
    }

    list.remove_back();  // [3]
    CHECK(list.front() && list.front()->value == 3);
    CHECK(list.back() && list.back()->value == 3);
    {
      std::stringstream ss;
      ss << list;
      CHECK(ss.str() == "[3]\n");
    }

    list.remove_front();
    CHECK(list.isEmpty());
    CHECK(list.front() == nullptr);
    CHECK(list.back() == nullptr);
    {
      std::stringstream ss;
      ss << list;
      CHECK(ss.str() == "[]\n");
    }
  }

  // Clear works and resets ends
  {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.clear();
    CHECK(list.isEmpty());
    CHECK(list.front() == nullptr);
    CHECK(list.back() == nullptr);
  }

  {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    auto arr = static_cast<int*>(list);
    CHECK(arr[0] == 10);
    CHECK(arr[1] == 20);
    CHECK(arr[2] == 30);
  }

  return test::exit_with_summary("linked_list");
}

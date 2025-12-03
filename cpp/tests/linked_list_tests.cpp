#include <iostream>
#include <sstream>
#include <stdexcept>

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

  {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.reverse();

    std::stringstream ss;
    ss << list;
    CHECK(ss.str() == "[40, 30, 20, 10]\n");
  }

  // get_kth_from_the_end
  {
    auto throws_out_of_range = [&](LinkedList& l, size_t k) {
      bool thrown = false;
      try {
        (void)l.get_kth_from_the_end(k);
      } catch (const std::out_of_range&) {
        thrown = true;
      }
      return thrown;
    };

    LinkedList list;

    CHECK(throws_out_of_range(list, 0));
    CHECK(throws_out_of_range(list, 1));

    list.push_back(10);
    auto node0 = list.get_kth_from_the_end(1);
    CHECK(node0->value == 10);
    CHECK(throws_out_of_range(list, 2));

    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    auto n0 = list.get_kth_from_the_end(1);
    CHECK(n0 && n0->value == 50);

    auto n1 = list.get_kth_from_the_end(2);
    CHECK(n1 && n1->value == 40);

    auto n4 = list.get_kth_from_the_end(5);
    CHECK(n4 && n4->value == 10);

    CHECK(throws_out_of_range(list, 6));
    CHECK(throws_out_of_range(list, 100));
  }

  // print_middle
  {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    std::stringstream ss;
    ss << list.print_middle();
    CHECK(ss.str() == "23");
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.push_back(11);
    {
      std::stringstream ss;
      ss << list.print_middle();
      CHECK(ss.str() == "6");
    }
  }

  // create_loop & has_loop
  {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    CHECK(list.has_loop() == false);
    CHECK(list.create_loop(3));
    CHECK(list.has_loop());
  }

  return test::exit_with_summary("linked_list");
}

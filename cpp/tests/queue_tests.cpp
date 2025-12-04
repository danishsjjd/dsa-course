#include <iostream>
#include <sstream>

#include "queue.hpp"
#include "test_utils.hpp"

int main() {
  {
    LinkedListQueue queue;
    CHECK(queue.is_empty());
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    {
      std::stringstream ss;
      ss << queue;
      CHECK(ss.str() == "[1, 2, 3, 4, 5]\n");
    }

    queue.dequeue();
    queue.dequeue();

    {
      std::stringstream ss;
      ss << queue;
      CHECK(ss.str() == "[3, 4, 5]\n");
    }

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    CHECK(queue.is_empty());

    {
      std::stringstream ss;
      ss << queue;
      CHECK(ss.str() == "[]\n");
    }
  }

  {
    LinkedListQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    {
      std::stringstream ss;
      ss << queue;
      CHECK(ss.str() == "[1, 2, 3, 4, 5]\n");
    }

    queue.reverse_to_kth(3);

    {
      std::stringstream ss;
      ss << queue;
      CHECK(ss.str() == "[3, 2, 1, 4, 5]\n");
    }
  }

  return test::exit_with_summary("queue");
}

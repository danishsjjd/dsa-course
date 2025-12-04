#include "linked_list.hpp"

class LinkedListQueue {
 public:
  ~LinkedListQueue();

  void enqueue(int value);
  int dequeue();
  void reverse_to_kth(int k);

  int peek() const;
  int size() const;
  int is_empty() const;
  friend std::ostream& operator<<(std::ostream& stream,
                                  const LinkedListQueue& list);

 private:
  LinkedList list;
};

inline std::ostream& operator<<(std::ostream& stream,
                                const LinkedListQueue& queue) {
  stream << queue.list;
  return stream;
};

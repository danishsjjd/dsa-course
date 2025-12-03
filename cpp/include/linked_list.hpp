#pragma once
#include <ostream>

struct Node {
  int value;
  Node* next;

  Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  void push_front(int value);
  void push_back(int value);
  void remove_front();
  void remove_back();
  void clear();
  void reverse();
  Node* get_kth_from_the_end(size_t k);
  bool create_loop(int from);

  const Node* front() const;
  const Node* back() const;
  size_t size() const;
  bool isEmpty() const;
  int indexof(int) const;
  bool contains(int) const;
  std::string print_middle() const;
  bool has_loop() const;

  explicit operator int*() const;

 private:
  Node* front_node = nullptr;
  Node* back_node = nullptr;
  size_t list_size = 0;
};

inline std::ostream& operator<<(std::ostream& stream, const LinkedList& list) {
  stream << "[";
  for (auto node = list.front(); node != nullptr; node = node->next) {
    if (node != list.front()) {
      stream << ", ";
    }
    stream << node->value;
  }
  stream << "]\n";
  return stream;
};

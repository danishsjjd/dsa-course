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

  const Node* front() const;
  const Node* back() const;
  size_t size() const;
  void push_front(int value);
  void push_back(int value);
  void remove_front();
  void remove_back();
  void clear();
  bool isEmpty();
  int indexof(int) const;
  bool contains(int) const;
  void reverse();

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

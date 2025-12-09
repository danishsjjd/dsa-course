#include "linked_list.hpp"

#include <sstream>

LinkedList::LinkedList()
    : front_node(nullptr), back_node(nullptr), list_size(0) {}

LinkedList::~LinkedList() { clear(); }

void LinkedList::push_front(int value) {
  auto node = new Node(value);

  if (this->is_empty()) {
    this->front_node = this->back_node = node;
  } else {
    node->next = this->front_node;
    this->front_node = node;
  }

  this->list_size++;
}

void LinkedList::push_back(int value) {
  auto node = new Node(value);
  if (this->is_empty()) {
    this->front_node = this->back_node = node;
  } else {
    this->back_node->next = node;
    this->back_node = node;
  }
  this->list_size++;
}

void LinkedList::remove_front() {
  if (is_empty()) {
    return;
  }

  Node* to_delete = front_node;
  front_node = front_node->next;

  if (front_node == nullptr) {
    back_node = nullptr;
  }

  delete to_delete;
  this->list_size--;
}

void LinkedList::clear() {
  while (!this->is_empty()) {
    this->remove_front();
  }
}

void LinkedList::reverse() {
  Node* previous = nullptr;
  auto current = this->front_node;

  while (current) {
    auto temp = current->next;
    current->next = previous;
    previous = current;
    current = temp;
  }

  this->back_node = this->front_node;
  this->front_node = previous;
}

Node* LinkedList::get_kth_from_the_end(size_t k) {
  auto current = this->front_node;
  Node* found = nullptr;
  size_t index = 1;

  while (current) {
    if (index == k) {
      found = this->front_node;
    } else if (found != nullptr) {
      found = found->next;
    }

    current = current->next;
    index++;
  }

  if (found != nullptr) {
    return found;
  }

  throw std::out_of_range("k is larger than the list size");
}

bool LinkedList::create_loop(int from) {
  auto current = this->front_node;
  while (current) {
    if (current->value == from) {
      this->back_node->next = current;
      return true;
    }

    current = current->next;
  }

  return false;
}

const Node* LinkedList::front() const { return this->front_node; }

const Node* LinkedList::back() const { return this->back_node; }

size_t LinkedList::size() const { return this->list_size; }

bool LinkedList::is_empty() const { return this->list_size == 0; }

int LinkedList::indexof(int value) const {
  size_t index = 0;
  Node* to_find = this->front_node;

  while (to_find != nullptr) {
    if (to_find->value == value) {
      return index;
    }

    to_find = to_find->next;
    index++;
  }

  return -1;
}

bool LinkedList::contains(int value) const {
  return this->indexof(value) != -1;
}

std::string LinkedList::print_middle() const {
  if (this->is_empty()) {
    return "";
  }

  auto a = this->front_node;
  auto b = this->front_node;
  while (b != this->back_node && b->next != this->back_node) {
    b = b->next->next;
    a = a->next;
  }

  std::stringstream ss;
  if (b == this->back_node) {
    ss << a->value;
  } else {
    ss << a->value << b->value;
  }

  return ss.str();
}

bool LinkedList::has_loop() const {
  // Floyd’s Cycle-finding Algorithm
  // Use two pointers (slow and fast) to traverse the list. Move the slow
  // pointer one step forward and the fast pointer two steps forward. If there’s
  // a loop, at some point, the fast pointer will meet the slow pointer and
  // overtake it.
  auto slow = this->front_node;
  auto fast = this->front_node;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  };

  return false;
}

LinkedList::operator int*() const {
  size_t list_size = this->size();

  if (list_size == 0) {
    return nullptr;
  }

  int* arr = new int[list_size];

  Node* current = this->front_node;
  size_t index = 0;
  while (current != nullptr) {
    arr[index++] = current->value;
    current = current->next;
  }

  return arr;
}

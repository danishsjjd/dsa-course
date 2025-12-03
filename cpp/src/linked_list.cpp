#include "linked_list.hpp"

#include <sstream>

LinkedList::LinkedList()
    : front_node(nullptr), back_node(nullptr), list_size(0) {}

LinkedList::~LinkedList() { clear(); }

void LinkedList::push_front(int value) {
  auto node = new Node(value);
  if (this->isEmpty()) {
    this->front_node = this->back_node = node;
  } else {
    node->next = this->front_node;
    this->front_node = node;
  }
  this->list_size++;
}

void LinkedList::push_back(int value) {
  auto node = new Node(value);
  if (this->isEmpty()) {
    this->front_node = this->back_node = node;
  } else {
    this->back_node->next = node;
    this->back_node = node;
  }
  this->list_size++;
}

const Node* LinkedList::front() const { return this->front_node; }

const Node* LinkedList::back() const { return this->back_node; }

bool LinkedList::isEmpty() const { return this->list_size == 0; }

void LinkedList::remove_front() {
  if (isEmpty()) {
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

void LinkedList::remove_back() {
  if (isEmpty()) {
    return;
  }

  if (this->front_node == this->back_node) {
    delete this->front_node;
    this->front_node = this->back_node = nullptr;
    this->list_size--;
    return;
  }

  Node* second_last_node = this->front_node;

  while (second_last_node->next != this->back_node) {
    second_last_node = second_last_node->next;
  }

  second_last_node->next = nullptr;
  delete this->back_node;
  this->back_node = second_last_node;
  this->list_size--;
}

void LinkedList::clear() {
  while (!this->isEmpty()) {
    this->remove_front();
  }
}

bool LinkedList::contains(int value) const {
  return this->indexof(value) != -1;
}

bool isEven(int value) { return value % 2 == 0; }

std::string LinkedList::print_middle() const {
  if (isEmpty()) {
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

  // INFO: below is how I originally implement it
  // auto current = this->front_node;
  // int size = 1;

  // auto middle1 = current;
  // Node* middle2 = nullptr;

  // while (current) {
  //   if (isEven(size)) {
  //     middle2 = middle1->next;
  //   } else if (middle2 != nullptr) {
  //     middle1 = middle2;
  //     middle2 = nullptr;
  //   }

  //   current = current->next;
  //   size++;
  // }

  // std::stringstream ss;
  // if (middle1 != nullptr) {
  //   ss << middle1->value;
  //   if (middle2 != nullptr) {
  //     ss << middle2->value;
  //   }
  // }

  // return ss.str();
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

bool LinkedList::has_loop() const {
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

size_t LinkedList::size() const { return this->list_size; }

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

#include "linked_list.hpp"

LinkedList::LinkedList() : front_node(nullptr), back_node(nullptr) {}

LinkedList::~LinkedList() { clear(); }

void LinkedList::push_front(int value) {
  auto node = new Node(value);
  if (this->isEmpty()) {
    this->front_node = this->back_node = node;
  } else {
    node->next = this->front_node;
    this->front_node = node;
  }
}

void LinkedList::push_back(int value) {
  auto node = new Node(value);
  if (this->isEmpty()) {
    this->front_node = this->back_node = node;
  } else {
    this->back_node->next = node;
    this->back_node = node;
  }
}

const Node* LinkedList::front() const { return this->front_node; }

const Node* LinkedList::back() const { return this->back_node; }

bool LinkedList::isEmpty() { return this->front_node == nullptr; }

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
}

void LinkedList::remove_back() {
  if (isEmpty()) {
    return;
  }

  if (this->front_node == this->back_node) {
    delete this->front_node;
    this->front_node = this->back_node = nullptr;
    return;
  }

  Node* second_last_node = this->front_node;

  while (second_last_node->next != this->back_node) {
    second_last_node = second_last_node->next;
  }

  second_last_node->next = nullptr;
  delete this->back_node;
  this->back_node = second_last_node;
}

void LinkedList::clear() {
  while (!this->isEmpty()) {
    this->remove_front();
  }
}

bool LinkedList::contains(int value) const {
  return this->indexof(value) != -1;
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

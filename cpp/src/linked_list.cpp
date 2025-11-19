#include "linked_list.hpp"

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

bool LinkedList::isEmpty() { return this->list_size == 0; }

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

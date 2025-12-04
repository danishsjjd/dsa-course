#include "queue.hpp"

LinkedListQueue::~LinkedListQueue() { this->list.clear(); }

void LinkedListQueue::enqueue(int value) { this->list.push_back(value); }

int LinkedListQueue::dequeue() {
  if (this->is_empty()) {
    throw std::out_of_range("Cannot dequeue from an empty queue");
  }

  int value = this->list.front()->value;
  this->list.remove_front();
  return value;
}

void LinkedListQueue::reverse_to_kth(int k) {
  LinkedListQueue temp_queue;

  if (k > this->size()) {
    throw std::out_of_range("k is larger than the list size");
  }

  auto count = 0;

  while (count != k) {
    temp_queue.enqueue(this->dequeue());
    count++;
  }

  while (!temp_queue.is_empty()) {
    this->list.push_front(temp_queue.dequeue());
  }
}

int LinkedListQueue::peek() const { return this->list.front()->value; }

int LinkedListQueue::size() const { return this->list.size(); }

int LinkedListQueue::is_empty() const { return this->list.is_empty(); }

#include "array.hpp"

Array::Array(int length) : length(length), items(new int[length]), count(0) {}

Array::~Array() { delete[] items; }

void Array::insert(int item) {
  if (this->count >= length) {
    length *= 2;

    auto newItems = new int[length];

    for (int i = 0; i < this->count; i++) {
      newItems[i] = this->items[i];
    }

    delete[] this->items;
    this->items = nullptr;

    this->items = newItems;
  }

  this->items[this->count] = item;

  this->count++;
}

void Array::insert_at(int item, int index) {
  if (this->count == 0 && index == 0) {
    this->insert(item);
    return;
  }

  if (index < 0 || index >= this->count) {
    return;
  }

  auto item_to_insert = item;

  for (int i = index; i <= this->count; i++) {
    if (i == this->count) {
      this->insert(item_to_insert);
      break;
    } else {
      auto temp = this->items[i];
      this->items[i] = item_to_insert;
      item_to_insert = temp;
    }
  }
}

void Array::remove_at(int index) {
  if (index < 0 || index >= this->count) {
    throw std::out_of_range("Index out of bounds");
  }

  for (int i = index; i < this->count; i++) {
    this->items[i] = this->items[i + 1];
  }

  this->count--;
}

void Array::reverse() {
  auto newItems = new int[this->count];
  for (int i = 0; i < this->count; i++) {
    newItems[i] = this->items[this->count - i - 1];
  }

  delete[] this->items;
  this->items = newItems;
}

int Array::indexof(int item) const {
  for (int i = 0; i < this->count; i++) {
    if (this->items[i] == item) {
      return i;
    }
  }

  return -1;
}

int Array::max_index() const {
  if (this->count == 0) {
    return -1;
  }

  auto idx = 0;
  auto maxElement = this->items[idx];
  for (int i = 0; i < this->count; i++) {
    auto element = this->items[i];
    if (element > maxElement) {
      maxElement = element;
      idx = i;
    }
  }

  return idx;
}

Array* Array::intersect(const Array& other) const {
  auto array = new Array(this->count);

  for (int i = 0; i < this->count; i++) {
    if (other.indexof(this->items[i]) == -1) {
      continue;
    }

    array->insert(this->items[i]);
  }

  return array;
}

std::ostream& operator<<(std::ostream& stream, const Array& array) {
  for (int i = 0; i < array.count; i++) {
    stream << array.items[i];
  }

  return stream;
}

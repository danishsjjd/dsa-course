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

std::ostream& Array::print(std::ostream& stream) const {
  for (int i = 0; i < this->count; i++) {
    stream << this->items[i];
  }

  return stream;
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

int Array::indexof(int item) {
  for (int i = 0; i < this->count; i++) {
    if (this->items[i] == item) {
      return i;
    }
  }

  return -1;
}

std::ostream& operator<<(std::ostream& stream, const Array& array) {
  return array.print(stream);
}

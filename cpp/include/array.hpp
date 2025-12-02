#pragma once

#include <iostream>

class Array {
 public:
  Array(int length);
  ~Array();

  void insert(int item);
  void insert_at(int item, int index);
  void remove_at(int index);
  void reverse();

  int indexof(int item) const;
  int max_index() const;
  Array* intersect(const Array& other) const;
  friend std::ostream& operator<<(std::ostream& stream, const Array& array);

 private:
  int length;
  int* items;
  int count;
};

std::ostream& operator<<(std::ostream& stream, const Array& array);

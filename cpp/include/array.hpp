#pragma once

#include <iostream>

class Array {
 public:
  Array(int length);
  void insert(int item);
  std::ostream& print(std::ostream& stream) const;
  void remove_at(int index);
  int indexof(int item);
  ~Array();

 private:
  int length;
  int* items;
  int count;
};

std::ostream& operator<<(std::ostream& stream, const Array& array);

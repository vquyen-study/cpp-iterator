#ifndef _FIXED_ARRAY_H_

#include <array>
#include <iostream>

#include "iterator-types.hpp"

#define _FIXED_ARRAY_H_

template<typename T, int size>
class fixed_array
{

  std::array<T, size> arr;

public:
  typedef typename xns::iterator<xns::input_iterator_tag, T> iterator;

  fixed_array()
  {
    int i = 1;
    for (auto& value : arr)
      value = i++;
  }

  void print_items()
  {
    for (auto& value : arr)
      std::cout << value << ", ";

    std::cout << std::endl;
  }

  iterator begin() { return arr.begin(); }
  iterator end() { return arr.end(); }
};

#endif //_FIXED_ARRAY_H_

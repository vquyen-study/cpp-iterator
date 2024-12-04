#include <bits/stdc++.h>

#include <array>

#include "fixed_array.hpp"
#include "iterator-types.hpp"

using namespace std;

int
main(int argc, char** argv)
{

  fixed_array<int, 20> my_arr;

  my_arr.print_items();

  cout << "Leng : " << xns::distance(my_arr.begin(), my_arr.end()) << endl;

  for (auto it = my_arr.begin(); it != my_arr.end(); ++it) {
    cout << *it << ",, ";
  }

  cout << endl;

  auto first = my_arr.begin();

  auto end = my_arr.end();

  cout << "while oloop---------------__> \n";
  while (first != end) {
    cout << *first << ", ";
    ++first;
  }

  return 0;
}

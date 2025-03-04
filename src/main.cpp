#include <algorithm>
#include <bits/stdc++.h>

#include <array>
#include <sstream>
#include <string>

#include "fixed_array.hpp"
#include "iterator-types.hpp"
#include "stream_iterator.hpp"

using namespace std;

int
main(int argc, char** argv)
{

  fixed_array<int, 20> my_arr;

  cout << endl;
  cout << endl;
  cout << endl;

  cout << "Print initailzed fixed_array: " << endl;
  my_arr.print_items();

  cout << "\nLeng : " << xns::distance(my_arr.begin(), my_arr.end()) << endl;

  cout << "\n Dereference accessing... " << endl;
  for (auto it = my_arr.begin(); it != my_arr.end(); ++it) {
    cout << *it << "...";
  }

  cout << endl;

  cout << "Algorithm checking.... \n";

  auto first = my_arr.begin();
  auto end = my_arr.end();
  int count = 0;

  while (first != end) {
    *first = 2;
    count++;
    if (count > 5) {
      break;
    }
    ++first;
  }

  count = std::count(my_arr.begin(), my_arr.end(), 2);
  cout << "\nCount algorithm std::count: " << count << endl;

  count =
    std::count_if(my_arr.begin(), my_arr.end(), [](int x) { return x == 2; });
  cout << "\nCount algorithm std::count_if: " << count << endl;

  cout << "\nfor std::copy : \n";
  vector<int> vec(my_arr.get_size(), 0);
  std::copy(my_arr.begin(), my_arr.end(), vec.begin());

  cout << "Vector is copied from fixed_array : ";
  for (auto& x : vec) {
    cout << x << ", ";
  }
  cout << endl;
  cout << "\nSorted array : ";
  sort(my_arr.begin(), my_arr.end(), greater<int>());
  for (auto& x : my_arr) {
    cout << x << ", ";
  }
  cout << endl;

  // istream_iterator test
  // cout << "\nistream_iterator test :\n";
  // string st("R.Rorty");

  // string re_01, re_02, re_03;
  // re_02 = ",H.Putnam";
  // re_03 = "D.Dennett,xxx,H.Putnam";

  cout << endl;
  cout << endl;
  cout << endl;

  std::istringstream str("0.1 0.2 0.3 0.4");
  std::partial_sum(xns::istream_iterator<double>(str),
                   xns::istream_iterator<double>(),
                   std::ostream_iterator<double>(std::cout, " "));

  std::istringstream str2("1 3 5 7 8 9 10");
  auto it = std::find_if(xns::istream_iterator<int>(str2),
                         xns::istream_iterator<int>(),
                         [](int i) { return i % 2 == 0; });

  cout << "\n The first even number is : " << str2.str() << " is ====> ";
  if (it != xns::istream_iterator<int>())
    std::cout << *it << ".\n";

  return 0;
}

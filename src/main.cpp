#include <bits/stdc++.h>

#include "iterator-types.h"
#include "fix_size_array.h"

using namespace std;

int
main(int argc, char** argv)
{

  vector<int> iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  list<int> lt = {1, 2, 3, 4, 5};
  xns::FixedSizeArray<int> farray(10);

  for (auto it = farray.begin(); it != farray.end(); ++it){
      std::cout << *it << std::endl;
  }
  // auto value = std::distance(farray.begin(), farray.end());
  // auto value = std::distance(lt.begin(), lt.end());
  auto value = xns::distance(farray.begin(), farray.end());
  cout << "distance between iterator: " << value << endl;
  return 0;
}

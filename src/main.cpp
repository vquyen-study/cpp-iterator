#include <bits/stdc++.h>

#include "iterator-types.h"
using namespace std;

int
main(int argc, char** argv)
{

  vector<int> iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  auto value = xns::distance(iv.begin(), iv.end());

  cout << "distance between iterator: " << value << endl;
  return 0;
}

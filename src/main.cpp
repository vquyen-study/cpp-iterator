#include <bits/stdc++.h>

#include "iterator-types.h"
#include "fix_size_array.h"
#include "algorithm.h"

using namespace std;

int
main(int argc, char** argv)
{
    vector<int> iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list<int> lt = {1, 2, 3, 4, 5};
    xns::FixedSizeArray<int> farray = { 1, 2, 3, 4, 5, 2, 7, 8, 2, 10 };

    // C loop stype
    std::cout << "C loop stype" << std::endl;
    for (size_t index = 0; index < farray.capacity(); ++index){
        std::cout << farray[index] << std::endl;
    }

    // stype loop with iterator
    std::cout << "Stype Iterator loop" << std::endl;
    for (auto it = farray.begin(); it != farray.end(); ++it){
        std::cout << *it << std::endl;
    }

    // range base for loop
    std::cout << "Range base for loop" << std::endl;
    for (auto it : farray){
        std::cout << it << std::endl;
    }

    auto value = xns::distance(farray.begin(), farray.end());
    cout << "distance between iterator: " << value << endl;
    auto vi = farray.begin();
    xns::advance(vi, 2);
    std::cout << "Advance begin with 2: "<< *vi << std::endl;

    vi = xns::next(vi);
    std::cout << "Next: "<< *vi << std::endl;

    vi = xns::prev(vi);
    std::cout << "Previous: "<< *vi << std::endl;
    std::cout << "Count value 2 in container: " << xns::count(farray.begin(), farray.end(), 2) << std::endl;

    return 0;
}

#include "frost_alloc.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int ia[5] = { 1, 2, 3, 4, 5 };

    // vector<int, frost::allocator<int> > iv(ia, ia + 5);
    vector<int, std::allocator<int> > iv(ia, ia + 5);
    for(size_t i = 0; i < iv.size(); ++i)
        cout << iv[i] << " ";
    cout << endl;

    return 0;
}

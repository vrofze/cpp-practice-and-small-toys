#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> coll;
    for(int i = 1; i <= 10; ++i)
        coll.push_back(i);

    int res = count_if(coll.begin(), coll.end(), bind1st(less<int>(), 10));
    cout << res << endl;

    res = count_if(coll.begin(), coll.end(), bind2nd(less<int>(), 10));
    cout << res << endl;
}

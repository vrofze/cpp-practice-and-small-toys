#include <cstdlib>
#include <iostream>

using namespace std;

int fcmp(const void* eleme1, const void* eleme2);

template<class T>
struct plust
{
    T operator()(const T& x, const T& y) const
        {
            return x + y;
        }
};

template<class T>
struct mins
{
    T operator()(const T& x, const T& y) const
        {
            return x - y;
        }
};

int main()
{
    int ia[10] = { 32, 92, 67, 58, 10, 4, 25, 52, 59, 54 };

    for(int i = 0; i < 10; ++i)
        cout << ia[i] << " ";
    cout << endl;

    qsort(ia, sizeof(ia) / sizeof(int), sizeof(int), fcmp);

    for(int i = 0; i < 10; ++i)
        cout << ia[i] << " ";
    cout << endl;

    cout << plust<int>() (43, 50) << endl;
    cout << mins<int>() (43, 50) << endl;

    return 0;
}

int fcmp(const void* elem1, const void* elem2)
{
    const int* i1 = (const int*)elem1;
    const int* i2 = (const int*)elem2;

    if(*i1 < *i2)
        return -1;
    else if(*i1 > *i2)
        return 1;
    else return 0;
}

#include "binary_search.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "int put the length of the array:";
    int length;
    cin >> length;
    int *arr = new int[length];
    cout << "input " << length << " elements:";
    for(int i = 0; i < length; ++i)
        cin >> arr[i];
    cout << "input the element to search:";
    int goal;
    cin >> goal;

    int index = binary_search(arr, length, goal);

    cout << index + 1 << endl;

    return 0;
}

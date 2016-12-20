#include "merge_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "heap_sort.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "input the number of the array:";
    size_t n;
    cin >> n;
    int *arr = new int[n];
    cout << "input " << n << " numbers: ";
    for(size_t i = 0; i < n; ++i)
        cin >> arr[i];

    // insertion_sort(arr, n);
    // merge_sort(arr, n);
    // bubble_sort(arr, n);
    heap_sort(arr, n);

    for(size_t i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

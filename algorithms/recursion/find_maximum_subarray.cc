#include <climits>
#include <iostream>
#include <tuple>

using namespace std;

typedef tuple<size_t, size_t, int> Tuple;

Tuple find_max_crossing_subarray(int arr[], size_t low, size_t mid, size_t high)
{
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;
    size_t max_left, max_right;
    for(int i = mid; i >= (int)low; --i){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    sum = 0;
    for(size_t i = mid + 1; i <= high; ++i){
        sum += arr[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }

    return make_tuple(max_left, max_right, left_sum + right_sum);
}

Tuple find_maximum_subarray(int arr[], size_t low, size_t high)
{
    if(low == high)
        return make_tuple(low, high, arr[low]);
    else {
        size_t mid = (low + high) / 2;
        Tuple left = find_maximum_subarray(arr, low, mid);
        Tuple cross = find_max_crossing_subarray(arr, low, mid, high);
        Tuple right = find_maximum_subarray(arr, mid + 1, high);

        int max_left = get<2>(left);
        int max_cross = get<2>(cross);
        int max_right = get<2>(right);

        if(max_left >= max_cross && max_left >= max_right)
            return left;
        else if(max_cross >= max_left && max_cross >= max_right)
            return cross;
        else
            return right;
    }
}

int main()
{
    cout << "input the number of the array:";
    size_t num;
    cin >> num;
    cout << "input "<< num <<  " numbers:";
    int *arr = new int[num];
    for(size_t i = 0; i < num; ++i){
        cin >> arr[i];
    }

    Tuple result = find_maximum_subarray(arr, 0, num - 1);

    cout << "low:" << get<0>(result)
         << " high:" << get<1>(result)
         << " sum:" << get<2>(result)
         << endl;
    // for(size_t i = 0; i < num; ++i)
    //     cout << arr[i] << " ";
    // cout << endl;
}



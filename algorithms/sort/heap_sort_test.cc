#include <iostream>

#define left(x) x << 1;
#define right(x) (x << 1) + 1;

template<class T>
void swap(T &n, T &m)
{
    T temp = n;
    n = m;
    m = temp;
}

template<class T>
class Heap
{
public:
    void max_heapify(size_t);

private:
    T *arr;
    size_t heap_size;
    size_t lenght;
};

int main()
{
    int i = 4;
    std::cout << (i << 10) << std::endl;
    return 0;
}

template<class T>
void max_heapify(T arr[], size_t i)
{
    T l = left(i);
    T r = right(i);

    T largest;
    if(l <= sizeof(arr) / sizeof(T) && arr[l] > arr[i])
        largest = l;
    else largest = i;
    if(r <= sizeof(arr) / sizeof(T) && arr[r] > arr[i])
        largest = r;
    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest);
    }
}

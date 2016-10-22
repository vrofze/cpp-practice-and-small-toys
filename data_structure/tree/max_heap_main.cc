#include "max_heap.h"

#include <iostream>

int main()
{
  MaxHeap<int> heap;
  int arr[] = {0, 20, 12, 35, 15, 10, 80, 30, 17, 2, 1};
  std::cout << "here" << std::endl;
  heap.initialize(arr, 11);
  std::cout << "here" << std::endl;
  // std::cout << heap.pop() << std::endl;
}

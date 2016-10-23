#include "max_heap.h"

#include <iostream>

int main()
{
  MaxHeap<int> heap;
  int arr[] = {20, 12, 35, 15, 10, 80, 30, 17, 2, 1};
  heap.initialize(arr, 10);
  std::cout << heap << std::endl;
  std::cout << heap.pop() << std::endl;
  std::cout << heap << std::endl;
  heap.push(90);
  heap.push(90);
  heap.push(100);
  heap.push(90);
  std::cout << heap << std::endl;
  std::cout << heap.pop() << std::endl;
  std::cout << heap.pop() << std::endl;
  std::cout << heap.pop() << std::endl;
  std::cout << heap.pop() << std::endl;
  std::cout << heap.pop() << std::endl;
  std::cout << heap << std::endl;
}

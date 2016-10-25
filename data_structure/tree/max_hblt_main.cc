#include "max_hblt.h"

#include <iostream>

int main()
{
  MaxHblt<int> hblt;
  std::cout << hblt.empty() << std::endl;
  int arr[] = {3, 5, 6, 7, 20, 8, 2, 9, 12, 15, 30, 17};
  hblt.initialize(arr, 12);
  std::cout << hblt.empty() << std::endl;
  std::cout << hblt.size() << std::endl;
  hblt.PreOrderOutput();
  std::cout << hblt.pop() << std::endl;
  hblt.PreOrderOutput();
  std::cout << hblt.pop() << std::endl;
  hblt.PreOrderOutput();
  hblt.push(1);
  hblt.PreOrderOutput();
  hblt.push(100);
  hblt.PreOrderOutput();
  return 0;
}

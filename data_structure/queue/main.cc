#include "array_queue.h"

#include <iostream>

int main()
{
  ArrayQueue<int> queue;
  if(queue.empty())
    std::cout << "queue is empty" << std::endl;
  queue.push(10);
  queue.push(20);
  std::cout << queue << std::endl;
  queue.pop();
  std::cout << queue << std::endl;
  queue.push(30);
  queue.push(40);
  queue.push(50);
  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();
  std::cout << queue << std::endl;
  queue.push(50);
  queue.push(10);
  queue.push(20);
  queue.push(30);
  queue.push(40);
  queue.push(50);
  queue.push(60);
  queue.push(50);
  queue.push(50);
  queue.push(50);
  queue.push(50);
  queue.push(50);
  queue.push(50);
  queue.push(50);
  std::cout << queue << std::endl;
  std::cout << "queue.front:" << queue.front() << std::endl;
  std::cout << "queue.back:" << queue.back() << std::endl;
  std::cout << "queue size:" << queue.size() << std::endl;
  std::cout << queue.pop() << std::endl;
  std::cout << queue << std::endl;

  return 0;
}

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

template<class T>
class PriorityQueue
{
 public:
  virtual ~PriorityQueue() { }
  virtual bool empty() const = 0;
  virtual size_t size() const = 0;
  virtual const T& top() = 0;
  virtual T pop() = 0;
  virtual void push(const T& element) = 0;
};

#endif

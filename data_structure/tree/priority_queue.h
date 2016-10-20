#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template<class T>
class PriorityQueueADT
{
 public:
  virtual ~PriorityQueueADT() { }
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual const T& top() = 0;
  virtual T pop() = 0;
  virtual void push(const T& element) = 0;
};

#endif

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "queue.h"
#include <iostream>

template<class T>
class ArrayQueue: public Queue<T>
{
 public:
  ArrayQueue();
  ArrayQueue(const ArrayQueue<T>&);
  bool empty() const {return qfront == qback; }
  int size() const {
    return (qback - qfront + queue_size) % queue_size;
  }
  T& front();
  T& back();
  T pop();
  void push(const T& element);
  void output(std::ostream& out) const;

 private:
  T* queue;
  int qfront, qback;
  int queue_size;
  inline int convert(int i) const// 转换索引
  {
    return i % queue_size;
  }
  void change_length();
};

template<class T>
ArrayQueue<T>::ArrayQueue(): queue_size(10)
{
  queue = new T[10];
  qfront  = qback = 0;
}

template<class T>
T& ArrayQueue<T>::front()
{
  return queue[convert(qfront + 1)];
}

template<class T>
T& ArrayQueue<T>::back()
{
  return queue[qback];
}

template<class T>
T ArrayQueue<T>::pop()
{
  if(qfront == qback){
    std::cout << "queue is empty" << std::endl;
    return T();
  }
  T data = queue[convert(qfront + 1)];
  queue[qfront].~T();
  qfront = convert(qfront + 1);
  queue[qfront] = T();
  return data;
}

template<class T>
void ArrayQueue<T>::push(const T& element)
{
  if(convert(qback + 1) == qfront){
    change_length();
  }
  qback = convert(qback+1);
  queue[qback] = element;
}

template<class T>
void ArrayQueue<T>::change_length()
{
  T* new_queue = new T[2 * queue_size];
  int new_qback = 1;
  for(int i = convert(qfront + 1); convert(i) != qback; ++i, ++new_qback){
    new_queue[new_qback] = queue[convert(i)];
  } // 当qback为queue_size - 1时<=判定失效,故使用!=
  new_queue[new_qback] = queue[qback]; // 复制queue[qback]
  qfront = 0;
  qback = new_qback;
  queue_size = 2 * queue_size;
  delete[] queue;
  queue = new_queue;
}

template<class T>
void ArrayQueue<T>::output(std::ostream& out) const
{
  if(qfront == qback){
    out << "the queue is empty" << std::endl;
    return;
  }
  for(int i = convert(qfront + 1); convert(i) != qback; ++i){
    out << queue[convert(i)] << " ";
  }
  out << queue[qback] << " ";
}

template<class T>
std::ostream& operator<<(std::ostream& out, const ArrayQueue<T>& queue)
{
  queue.output(out);
  return out;
}

#endif

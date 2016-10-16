#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

template<class T>
class Queue
{
 public:
  virtual ~Queue() { }
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual T& front() = 0; // 返回头元素的引用
  virtual T& back() = 0; // 返回尾元素的引用
  virtual T pop() = 0; // 删除并返回首元素
  virtual void push(const T& element) = 0; // 把元素element加入队尾
};

#endif

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "priority_queue.h"
#include <iostream>

template<class T>
class MaxHeap: public PriorityQueue<T>
{
 public:
  MaxHeap();
  MaxHeap(const MaxHeap&);
  ~MaxHeap() { delete[] heap; }

  bool empty() const { return heap_size == 0; }
  size_t size() const { return heap_size; }
  const T& top();
  T pop();
  void push(const T& element);
  void initialize(T *heap, size_t size);


 private:
  T* heap;
  size_t length;
  size_t heap_size;

  // 获得子节点中值较大的索引
  inline size_t max(size_t left, size_t right)
  {
    return heap[left] >= heap[right]? left: right;
  }

  // 将较大值置于t1
  inline size_t max_swap(size_t t1, size_t t2)
  {
    // t1 > t2
    if(heap[t1] >= heap[t2])
      return t1 ;
    else {
      T temp = heap[t1];
      heap[t1] = heap[t2];
      heap[t2] = temp;
      return t2;
    }
  }
};

template<class T>
MaxHeap<T>::MaxHeap()
{
  heap = new T[11];
  length = 10;
  heap_size = 0;
}

template<class T>
MaxHeap<T>::MaxHeap(const MaxHeap& heap)
{
  length = heap.length;
  heap_size = heap.heap_size;
  heap = new T[length];
  for(size_t i = 1; i <= heap_size; ++i){
    this->heap[i] = heap.heap[i];
  }
}

template<class T>
const T& MaxHeap<T>::top()
{
  // heap empty
  if(heap_size == 0){
    std::cout << "max heap is empty" << std::endl;
    return heap[0];
  }

  return heap[1];
}

template<class T>
T MaxHeap<T>::pop()
{
  // heap empty
  if(heap_size == 0){
    std::cout << "max heap is empty" << std::endl;
    return T();
  }

  T data = heap[1]; // 取出最大值

  // 由上往下处理
  // 把位于最后一位的值置于第一位
  heap[1] = heap[heap_size];
  size_t index = 1;

  // 当前节点存在子节点
  while(2 * index >= heap_size){
    if(2 * index + 1 > heap_size){
      max_swap(index, 2 * index); //仅有一个子节点
      break;
    }
    else {
      size_t n_index = max_swap(index, max(2 * index, 2 * index + 1)); // 将当前节点与子节点中较大值置于父节点,并返回原来较大节点索引
      if(n_index == index) break; // 当前节点大于任何一个子节点
    }
  }

  return data;
}

template<class T>
void MaxHeap<T>::push(const T& element)
{
  if(heap_size == length)
    {
      T* new_heap = new T[2 * length];
      for(size_t i = 1; i <= heap_size; ++i)
        new_heap[i] = heap[i];
      length *= 2;
      delete[] heap;
      heap = new_heap;
    }

  // 从下往上比较
  // 将element插入到最后一个位置
  heap[++heap_size] = element;
  size_t index = heap_size; // 插入元素所在的索引
  while(index > 0){
    size_t n_index = max_swap(index / 2, index); // 将较大值置于父节点,并获取交换前较大值的索引
    if(n_index != index) // 父节点大于插入节点
      break;
    else
      index = n_index; // 父节点小于插入节点
  }
}

template<class T>
void MaxHeap<T>::initialize(T* heap, size_t size)
{
  delete[] this->heap;
  this->heap = heap;
  heap_size = size;

  for(size_t i = heap_size / 2; i >= 1; --i){
    std::cout << "i:" << i << std::endl;
    size_t index = i;
    while(2 * index <= heap_size){
      std::cout << "index:" << index << std::endl;
      if(2 * index + 1 > heap_size){
        max_swap(index, 2 * index);
        break;
      } else {
        std::cout << "ha:" << 2*index+1 << std::endl;
        size_t n_index = max_swap(index, max(2 * index, 2 * index + 1));
        std::cout << "n_index:" << n_index << std::endl;
        if(n_index == index)
          break;
        else
          index = n_index;
      }
    }
  }
}

#endif

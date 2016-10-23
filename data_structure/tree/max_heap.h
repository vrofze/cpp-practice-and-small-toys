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
  void initialize(const T *heap, size_t size);
  void output(std::ostream &out) const;


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
    return heap[0]; // heap为空返回数组初始值
  }

  return heap[1];
}

/*
template<class T>
T MaxHeap<T>::pop()
{
  // heap empty
  if(heap_size == 0){
    std::cout << "max heap is empty" << std::endl;
    return heap[0]; // heap为空返回数组初始值
  }

  T data = heap[1]; // 取出最大值

  // 由上往下处理
  // 把位于最后一位的值置于第一位
  heap[1] = heap[heap_size--];
  size_t index = 1;

  // 当前节点存在子节点
  while(2 * index <= heap_size){
    if(2 * index + 1 > heap_size){
      max_swap(index, 2 * index); //仅有一个子节点
      break;
    }
    else {
      size_t n_index = max_swap(index, max(2 * index, 2 * index + 1)); // 将当前节点与子节点中较大值置于父节点,并返回原来较大节点索引
      if(n_index == index)
        break; // 当前节点大于任何一个子节点
      else
        index = n_index;
    }
  }

  return data;
}
*/

template<class T>
T MaxHeap<T>::pop()
{
  if(heap_size == 0){
    std::cout << "heap is empty" << std::endl;
  }

  T data = heap[1]; // 取出的最大值
  T last_element = heap[heap_size--]; // 原堆中最后一个元素,提出

  size_t index = 1;
  size_t child = 2 * index; // 当前位置的第一个子节点
  while(child <= heap_size){
    if(child + 1 <= heap_size) // 存在两个子节点
      child = max(child, child + 1); // 当前元素与子节点中较大的比较

    if(heap[child] <= last_element)
      break; // 子节点中较大者小于当前元素
    else {
      heap[index] = heap[child]; // 子节点中较大者大于当前元素,交换位置
      index = child; // 当前元素位置变为子节点位置
      child = 2 * index;
    }
  }
  heap[index] = last_element;
  return data;
}

/*
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
  while(index / 2 > 0){
    size_t n_index = max_swap(index / 2, index); // 将较大值置于父节点,并获取交换前较大值的索引
    if(n_index != index) // 父节点大于插入节点
      break;
    else{
      index = index / 2; // 父节点小于插入节点
    }
  }
}
*/

template<class T>
void MaxHeap<T>::push(const T& element)
{
  // 数组长度不足,数组长度加倍
  if(heap_size == length){
    T* new_heap = new T[2 * length];
    for(size_t i = 1; i <= heap_size; ++i)
      new_heap[i] = heap[i];
    length *= 2;
    delete[] heap;
    heap = new_heap;
  }

  size_t index = ++heap_size; // heap_size 加一
  while(index != 1 && heap[index / 2] < element){
    heap[index] = heap[index / 2]; // 插入元素大于其父节点
    index /= 2; // 插入元素位置变为父节点位置
  }

  heap[index] = element; // 找到合适插入位置
}

/*
template<class T>
void MaxHeap<T>::initialize(T* heap, size_t size)
{
  delete[] this->heap;
  this->heap = new T[size + 1];
  for(int i = 0; i <= size; ++i)
    this->heap[i + 1] = heap[i];
  heap_size = size;

  // 由heap_size/2 ---> 1处理每个子堆
  for(size_t i = heap_size / 2; i >= 1; --i){
    size_t index = i;
    while(2 * index <= heap_size){
      if(2 * index + 1 > heap_size){
        max_swap(index, 2 * index);
        break;
      } else {
        size_t n_index = max_swap(index, max(2 * index, 2 * index + 1));
        if(n_index == index)
          break;
        else
          index = n_index;
      }
    }
  }
}
*/

template<class T>
void MaxHeap<T>::initialize(const T *the_heap, size_t size)
{
  delete[] heap; // 删除原堆
  heap = new T[size + 1];
  for(size_t i = 0; i <= size; ++i)
    heap[i + 1] = the_heap[i]; // 堆从heap[1] 开始
  heap_size = size;

  for(size_t i = heap_size / 2; i >= 1; --i){
    T root_element = heap[i]; // 每个堆的根元素
    size_t child = i * 2; // 当前元素的第一个孩子元素位置
    while(child >= heap_size){
      if(child + 1 >= heap_size) //当前元素的第二个孩子存在
        child = max(child, child + 1);

      if(heap[child] <= root_element)
        break; // 当前元素位置即为当前位置
      else{ // 子节点中较大者大于当前元素
        heap[child / 2] = heap[child]; // 将子元素提前到父节点位置
        child = 2 * child;
      }
    }
    heap[child / 2] = root_element;
  }
}

template<class T>
void MaxHeap<T>::output(std::ostream &out) const
{
  for(int i = 1; i <= heap_size; ++i)
    out << heap[i] << " ";
}

template<class T>
std::ostream& operator<<(std::ostream& out, const MaxHeap<T> &heap)
{
  heap.output(out);
  return out;
}

#endif

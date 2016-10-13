#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "stack.h"
#include <iostream>

template<typename T>
class ArrayStack: public Stack<T>
{
 public:
  ArrayStack(int length = 10);
  ~ArrayStack() { delete[] stack; }
  bool empty() const { return top == -1; }
  int size() const { return top + 1; }
  T pop();
  void push(const T& element);
  void output(std::ostream& out) const;

 private:
  // 栈顶位置,栈为空时为-1
  int top;
  int length;
  T *stack;
};

template<typename T>
ArrayStack<T>::ArrayStack(int length) : length(length)
{
  if(length < 1)
    throw "length must > 1";

  top = -1;
  stack = new T[length];
}

template<typename T>
T ArrayStack<T>::pop()
{
  if (length == 0)
    throw "stack is empty";

  T data = stack[top--];
  stack[top + 1].~T();
  return data;
}

template<typename T>
void ArrayStack<T>::push(const T& element)
{
  if(top + 1 == length){
    std::cout << "push error, the stack is empty" << std::endl;
    return;
  }

  stack[++top] = element;
}

template<typename T>
void ArrayStack<T>::output(std::ostream& out) const
{
  for(int i = 0; i <= top; ++i)
    out << stack[i] << " ";
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const ArrayStack<T>& stack)
{
  stack.output(out);
  return out;
}

#endif

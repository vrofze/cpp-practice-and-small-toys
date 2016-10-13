#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "stack.h"
#include "../linear_list/LinkedList.h"

#include <iostream>

template<typename T>
class LinkedStack: public Stack<T>
{
 public:
  LinkedStack();
  ~LinkedStack();

  bool empty() const { return stack_size == 0; }
  int size() const { return stack_size; }
  T pop();
  void push(const T& element);
  void output(std::ostream& out) const;
  T test();

 private:
  LinkNode<T>* stack;
  int stack_size;
};

template<typename T>
LinkedStack<T>::LinkedStack(): stack_size(0)
{
  stack = nullptr;
}

template<typename T>
LinkedStack<T>::~LinkedStack()
{
  if(stack_size == 0)
    return;
  do{
    LinkNode<T>* delete_node = stack;
    stack = stack->next;
    delete delete_node;
  }while(stack != nullptr);
}

template<typename T>
T LinkedStack<T>::pop()
{
  if(stack_size == 0){
    std::cout << "stack is empty" << std::endl;
    throw "stack is empty";
  }

  T data = stack->element;
  if(stack_size == 1){
    delete stack;
    stack = nullptr;
    stack_size--;
  }
  else{
    LinkNode<T>* delete_node = stack;
    stack = stack->next;
    delete delete_node;
    stack_size--;
  }
  return data;
}

template<typename T>
T LinkedStack<T>::test()
{
  return stack->element;
}

template<typename T>
void LinkedStack<T>::push(const T& element)
{
  if(stack_size == 0){
    stack = new LinkNode<T>(element, nullptr);
    stack_size++;
  }
  else{
    LinkNode<T>* new_node = new LinkNode<T>(element, stack);
    stack = new_node;
    stack_size++;
  }
}

template<typename T>
void LinkedStack<T>::output(std::ostream& out) const
{
  out << "---top---" << std::endl;
  LinkNode<T>* temp = stack;
  while(temp != nullptr){
    out << "  " << temp->element << std::endl;
    temp = temp->next;
  }
  out << "---bottom---" << std::endl;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack)
{
  stack.output(out);
  return out;
}

#endif

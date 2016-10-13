//#include "ArrayStack.h"
#include "LinkedStack.h"
#include <iostream>

using namespace std;

int main()
{
  //ArrayStack<int> stack(10);
  LinkedStack<int> stack;
  if(stack.empty())
    cout << "stack is empty" << endl;

  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  if(!stack.empty())
    cout << "stack length:" << stack.size() << endl;
  cout << stack << endl;
  cout << "pop:" << stack.pop() << endl;
  cout << stack << endl;
}

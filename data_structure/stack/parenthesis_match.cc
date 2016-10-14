#include "ArrayStack.h"
#include <iostream>

//  括号匹配
bool parenthesis_match(std::string expr)
{
  ArrayStack<int> stack;
  int length = expr.size();

  for(int i = 0; i < length; ++i){
    if(expr.at(i) =='(')
      stack.push(i);
    else
      if(expr.at(i) == ')'){
        // stack empty means no match left parenthesis
        if(stack.empty())
          return false;
        stack.pop();
      }
  }
  if(stack.empty())
    return true;
  else
    return false;
}

// main
int main()
{
  std::string expr;
  std::cout << "input a string:";
  std::cin >> expr;
  if(parenthesis_match(expr))
    std::cout << "matched" << std::endl;
  else
    std::cout << "not match" << std::endl;
  return 0;
}

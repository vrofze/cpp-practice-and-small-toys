#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
 public:
  // 需添加{}!
  virtual ~Stack() { };
  // 判断栈是否为空
  virtual bool empty() const = 0;
  // 获取栈的深度
  virtual int size() const = 0;
  // 将栈顶元素弹出
  virtual T pop() = 0;
  // 将元素压入栈
  virtual void push(const T& element) = 0;
};

#endif

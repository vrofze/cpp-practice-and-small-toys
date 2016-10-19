#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "bin_tree_node.h"

template<class T>
class BinaryTree
{
 public:
  virtual ~BinaryTree() { }
  virtual bool empty() const = 0;
  virtual int size() const = 0;

  // 二叉树的操作均基于遍历
  // 参数为int (*) (T*)函数指针,通过遍历执行操作
  virtual void PreOrder(void (*) (T *)) = 0; //前序遍历
  virtual void InOrder(void (*) (T *)) = 0; // 中序遍历
  virtual void PostOrder(void (*) (T *)) = 0; // 后序遍历
  virtual void LevelOrder(void (*) (T *)) = 0; // 层次遍历
};

#endif

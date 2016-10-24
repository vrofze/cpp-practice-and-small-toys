#ifndef MAX_HBLT_H
#define MAX_HBLT_H

#include "priority_queue.h"
#include "bin_tree_node.h"
#include "../queue/array_queue.h"

template<class T>
class MaxHblt: public PriorityQueue<T>
{
 public:
  MaxHblt()
    {
      root = nullptr;
      tree_size = 0;
    }
  ~MaxHblt();

  bool empty() const { return tree_size == 0; }
  size_t size() const { return tree_size; }
  void meld(MaxHblt<T>& hblt);
  const T& top();
  T pop();
  void push(const T& element);

 private:
  BinTreeNode<std::pair<int, T>>* root;
  size_t tree_size;

  void meld(BinTreeNode<std::pair<int, T>>* &left,
            BinTreeNode<std::pair<int, T>>* &right);
};

template<class T>
void MaxHblt<T>::meld(BinTreeNode<std::pair<int, T>>* &left,
                      BinTreeNode<std::pair<int, T>>* &right)
{
  // 递归结束条件,left right中有一个为空
  if(right == nullptr)
    return;
  if(left == nullptr)
    {
      left = right;
      right = nullptr;
      return;
    }

  // left right 均不为空
  // left < right 时,交换.即根较大者的根为合并后的根
  if(left->element.second < right->element.second){
    swap(left, right);
  }

  meld(left->right, right); // 递归调用, left为合并后的hblt

  // 处理合并后仍为hblt
  if(left->left == nullptr){
    left->left = left->right;
    left->right = nullptr;
    left->element.first = 1; // s值,即hblt的右路径的s值+1
  } else {
    if(left->left->element.first < left->right->element.first) // 合并后hblt的左子节点s值小于右子节点s值
      swap(left->left, left->right); // 交换
    left->element.first = left->right->element.first + 1; //合并hblt根节点为右子节点s值加1
  }
}

template<class T>
void MaxHblt<T>::meld(MaxHblt<T>& hblt)
{
  meld(root, hblt.root);
  tree_size += hblt.tree_size;
  hblt.root = nullptr;
  hblt.tree_size = 0;
}

template<class T>
const T& top()
{
  
}

#endif

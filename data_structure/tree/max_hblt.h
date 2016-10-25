#ifndef MAX_HBLT_H
#define MAX_HBLT_H

#include "priority_queue.h"
#include "bin_tree_node.h"
#include "linked_binary_tree.h"
#include "../queue/array_queue.h"

template<class T>
class MaxHblt:public LinkedBinaryTree<std::pair<int, T>>,
  public PriorityQueue<T>
{
 public:
  MaxHblt()
    {
      this->root = nullptr;
      this->tree_size = 0;
    }
  ~MaxHblt() { this->erase(); };

  bool empty() const { return this->tree_size == 0; }
  size_t size() const { return this->tree_size; }
  void meld(MaxHblt<T>& hblt);
  const T& top();
  T pop();
  void push(const T& element);
  void initialize(T *arr, int size);

 private:
  // BinTreeNode<std::pair<int, T>>* root;
  // size_t tree_size;

  void meld(BinTreeNode<std::pair<int, T>>* &left,
            BinTreeNode<std::pair<int, T>>* &right);
  // void erase(); // 析构
  // void erase(BinTreeNode<std::pair<int, T>> *); // 析构,递归调用
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
  meld(this->root, hblt.root);
  this->tree_size += hblt.tree_size;
  hblt.root = nullptr;
  hblt.tree_size = 0;
}

template<class T>
const T& MaxHblt<T>::top()
{
  // hblt为空
  if(this->root == nullptr){
    std::cout << "hblt is empty" << std::endl;
    throw " hblt is empty" ;
  }


  // hblt 不为空
  return this->root->element.second;
}

template<class T>
T MaxHblt<T>::pop()
{
  // hblt 为空
  if(this->root == nullptr){
    std::cout << "hblt is empty" << std::endl;
    T data;
    return data;
  }

  T data = this->root->element.second; // 返回当前hblt的根元素
  BinTreeNode<std::pair<int, T>> *left = this->root->left,
    *right = this->root->right;

  delete this->root;
  this->root = left;
  meld(this->root, right); // 将原hblt的左右子树合并
  --this->tree_size;
  return data;
}

template<class T>
void MaxHblt<T>::push(const T& element)
{
  // 建立一个只包含element的hblt
  BinTreeNode<std::pair<int, T>> *q = new BinTreeNode<std::pair<int, T>>(std::pair<int, T>(0, element));

  meld(this->root, q); // 将上建立的hblt与root合并
  ++this->tree_size;
}

template<class T>
void MaxHblt<T>::initialize(T *arr, int size)
{
  if(size == 1){
    this->root = new BinTreeNode<std::pair<int, T>>(std::pair<int, T>(1, arr[0]));
    return;
  }
  ArrayQueue<BinTreeNode<std::pair<int, T>> *> queue; // 栈,用于存放hblt
  this->erase(); // 将原hblt清除

  for(int i = 0; i < size; ++i) // 将数组放入栈中
    queue.push(new BinTreeNode<std::pair<int, T>>(std::pair<int, T>(1, arr[i])));
  for(int i = 0; i < size - 1; ++i) {// 处理size-1次
    BinTreeNode<std::pair<int, T>> *left = queue.pop();
    BinTreeNode<std::pair<int, T>> *right = queue.pop();
    meld(left, right);
    queue.push(left);
  }

  this->root = queue.pop();
  this->tree_size = size;
}

/*
template<class T>
void MaxHblt<T>::erase()
{
  erase(root);
}

template<class T>
void MaxHblt<T>::erase(BinTreeNode<std::pair<int, T>> *t)
{
  if(t != nullptr){
    erase(t->left);
    erase(t->right);
    delete t;
  }
}
*/

template<class T>
std::ostream& operator<<(std::ostream& out, const std::pair<int, T> &t)
{
  out << t.second << " ";
  return out;
}

#endif

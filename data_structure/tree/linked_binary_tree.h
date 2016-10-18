#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

#include "bin_tree_node.h"
#include "binary_tree.h"

#include <iostream>

template<class T>
class LinkedBinaryTree: public BinaryTree<T>
{
 public:
  LinkedBinaryTree()
    {
      root = nullptr;
      tree_size = 0;
    }
  ~LinkedBinaryTree() { erase(); }
  bool empty() const { return tree_size == 0; }
  int size() const { return tree_size; }
  void PreOrder(void (*visit)(BinTreeNode<T> *))
  {
    this->visit = visit;
    PreOrder(root);
  }
  void InOrder(void (*visit)(BinTreeNode<T> *))
  {
    this->visit = visit;
    InOrder(root);
  }
  void PostOrder(void (*visit)(BinTreeNode<T> *))
  {
    this->visit = visit;
    PostOrder(root);
  }
  void LevelOrder(void (*visit)(BinTreeNode<T> *))
  {
    this->visit = visit;
    LevelOrder(root);
  }
  void erase()
  {
    PostOrder(dispose);
  }
  void Output()
  {
    PreOrder(Output);
    std::cout << std::endl;
  }
  int height() const { return height(root); }

 private:
  BinaryTree<T>* root; // 指向根节点的指针
  int tree_size; //树的节点个数
  static void (*visit)(LinkedBinaryTree *); // 访问函数,绑定访问节点时的操作
  static void PreOrder(BinTreeNode<T> *);
  static void InOrder(BinTreeNode<T> *);
  static void PostOrder(BinTreeNode<T> *);
  static void LevelOrder(BinTreeNode<T> *);
  static void dispose(BinTreeNode<T> *t) { delete t; } // 删除节点
  static void Output(BinTreeNode<T> *t){ std::cout << t->element << " "; }
  int height(BinTreeNode<T> *t);
};

template<class T>
void LinkedBinaryTree<T>::PreOrder(BinTreeNode<T> *t)
{
  if(t != nullptr){
    LinkedBinaryTree<T>::visit(t);
    PreOrder(t->left);
    PreOrder(t->right);
  }
}

template<class T>
void LinkedBinaryTree<T>::InOrder(BinTreeNode<T> *t)
{
  if(t != nullptr){
    InOrder(t->left);
    LinkedBinaryTree<T>::visit(t);
    InOrder(t->right);
  }
}

template<class T>
void LinkedBinaryTree<T>::PostOrder(BinTreeNode<T> *t)
{
  if(t != nullptr){
    PostOrder(t->left);
    PostOrder(t->right);
    LinkedBinaryTree<T>::visit(t);
  }
}

template<class T>
int LinkedBinaryTree<T>::height(BinTreeNode<T> *t)
{
  if(t == nullptr)
    return 0;
  else{
    int hl = height(t->left); // 左子树的高度
    int hr = height(t->right); // 右子树的高度
    return hl >= hr ? hl: hr;
  }
}

#endif

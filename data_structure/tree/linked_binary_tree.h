#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

#include "bin_tree_node.h"
#include "binary_tree.h"
#include "../queue/array_queue.h"

#include <iostream>

/*
template<class T>
class LinkedBinaryTree: public BinaryTree<BinTreeNode<T> >
{
 public:
  LinkedBinaryTree()
    {
      root = nullptr;
      tree_size = 0;
    }
  LinkedBinaryTree(const LinkedBinaryTree& tree)
    {
      this->root = CopyCreateInOrder(tree.root);
    }
  ~LinkedBinaryTree() { erase(); }
  bool empty() const { return tree_size == 0; }
  int size() const { return tree_size; }
  void MakeTree();
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
  void PreOrderOutput()
  {
    PreOrder(Output);
    std::cout << std::endl;
  }
  int height() const { return height(root); }
  static void Output(BinTreeNode<T> *t){ std::cout << t->element << " "; }

 private:
  BinTreeNode<T>* root; // 指向根节点的指针
  int tree_size; //树的节点个数
  static void (*visit)(BinTreeNode<T> *); // 访问函数,绑定访问节点时的操作
  static void PreOrder(BinTreeNode<T> *);
  static void InOrder(BinTreeNode<T> *);
  static void PostOrder(BinTreeNode<T> *);
  static void LevelOrder(BinTreeNode<T> *);
  static void dispose(BinTreeNode<T> *t) { delete t; } // 删除节点
  int height(BinTreeNode<T> *t) const;

  BinTreeNode<T>* CopyCreateInOrder(const BinTreeNode<T> *);
};

template<class T>
void LinkedBinaryTree<T>::MakeTree()
{
  root = new BinTreeNode<T>('+', nullptr, nullptr);
  root->left = new BinTreeNode<T>('*', nullptr, nullptr);
  root->left->left = new BinTreeNode<T>('a', nullptr, nullptr);
  root->left->right = new BinTreeNode<T>('b', nullptr, nullptr);
  root->right = new BinTreeNode<T>('/', nullptr, nullptr);
  root->right->left = new BinTreeNode<T>('c', nullptr, nullptr);
  root->right->right = new BinTreeNode<T>('d', nullptr, nullptr);
  tree_size = 7;
}

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
void LinkedBinaryTree<T>::LevelOrder(BinTreeNode<T> *t)
{
  ArrayQueue<BinTreeNode<T>*> queue;
  BinTreeNode<T>* temp = t;
  while(temp != nullptr){
    if(temp->left != nullptr)
      queue.push(temp->left);
    if(temp->right != nullptr)
      queue.push(temp->right);
    LinkedBinaryTree<T>::visit(temp);
    if(queue.empty())
      break;
    temp = queue.pop();
  }
}

template<class T>
int LinkedBinaryTree<T>::height(BinTreeNode<T> *t) const
{
  if(t == nullptr)
    return 0;
  else{
    int hl = height(t->left); // 左子树的高度
    int hr = height(t->right); // 右子树的高度
    return hl >= hr ? ++hl: ++hr;
  }
}

template<class T>
BinTreeNode<T>* LinkedBinaryTree<T>::CopyCreateInOrder(const BinTreeNode<T> *t)
{
  BinTreeNode<T> * new_p = nullptr;
  if(t != nullptr){
    new_p = new BinTreeNode<T>(t->element,
                               CopyCreateInOrder(t->left),
                               CopyCreateInOrder(t->right));
  }
  return new_p;
}

// !!! 初始化静态函数指针 !!!
template<class T>
void (*LinkedBinaryTree<T>::visit)(BinTreeNode<T> *) = nullptr;
*/ // **************公用静态指针visit, 线程不安全?******************

template<class T>
class LinkedBinaryTree: public BinaryTree<BinTreeNode<T> >
{
 public:
  LinkedBinaryTree()
    {
      root = nullptr;
      tree_size = 0;
    }
  LinkedBinaryTree(const LinkedBinaryTree<T>& tree)
    {
      this->root = CopyCreatePreOrder(tree.root);
    }
  ~LinkedBinaryTree() { erase(); }

  bool empty() const { return tree_size == 0; }
  int size() const { return tree_size; }
  void MakeTree();
  void PreOrder(void (*visit)(BinTreeNode<T> *))
  {
    PreOrder(visit, root);
  }

  void InOrder(void (*visit)(BinTreeNode<T> *))
  {
    InOrder(visit, root);
  }

  void PostOrder(void (*visit)(BinTreeNode<T> *))
  {
    PostOrder(visit, root);
  }

  void LevelOrder(void (*visit)(BinTreeNode<T> *))
  {
    LevelOrder(visit, root);
  }

  void erase()
  {
    PostOrder(dispose);
  }

  void PreOrderOutput()
  {
    PreOrder(Output);
    std::cout << std::endl;
  }

  static void Output(BinTreeNode<T> *t)
  {
    std::cout << t->element << " ";
  }


  int height() const { return height(root); }

 private:
  BinTreeNode<T>* root;
  int tree_size;
  static void PreOrder(void (*)(BinTreeNode<T> *), BinTreeNode<T> *);
  static void InOrder(void (*)(BinTreeNode<T> *), BinTreeNode<T> *);
  static void PostOrder(void (*)(BinTreeNode<T> *), BinTreeNode<T> *);
  static void LevelOrder(void (*)(BinTreeNode<T> *), BinTreeNode<T> *);
  static void dispose(BinTreeNode<T> *t) { delete t; }; // 删除节点
  int height(BinTreeNode<T> *) const;

  BinTreeNode<T>* CopyCreatePreOrder(const BinTreeNode<T> *);

};

template<class T>
void LinkedBinaryTree<T>::MakeTree()
{
  root = new BinTreeNode<T>('+', nullptr, nullptr);
  root->left = new BinTreeNode<T>('*', nullptr, nullptr);
  root->left->left = new BinTreeNode<T>('a', nullptr, nullptr);
  root->left->right = new BinTreeNode<T>('b', nullptr, nullptr);
  root->right = new BinTreeNode<T>('/', nullptr, nullptr);
  root->right->left = new BinTreeNode<T>('c', nullptr, nullptr);
  root->right->right = new BinTreeNode<T>('d', nullptr, nullptr);
  tree_size = 7;
}

template<class T>
void LinkedBinaryTree<T>::PreOrder(void (*visit)(BinTreeNode<T> *), BinTreeNode<T> *t)
{
  if(t != nullptr){
    visit(t);
    PreOrder(visit, t->left);
    PreOrder(visit, t->right);
  }
}

template<class T>
void LinkedBinaryTree<T>::InOrder(void (*visit)(BinTreeNode<T> *), BinTreeNode<T> *t)
{
  if(t != nullptr){
    InOrder(visit, t->left);
    visit(t);
    InOrder(visit, t->right);
  }
}

template<class T>
void LinkedBinaryTree<T>::PostOrder(void (*visit)(BinTreeNode<T> *), BinTreeNode<T> *t)
{
  if(t != nullptr){
    PostOrder(visit, t->left);
    PostOrder(visit, t->right);
    visit(t);
  }
}

template<class T>
void LinkedBinaryTree<T>::LevelOrder(void (*visit)(BinTreeNode<T> *), BinTreeNode<T> *t)
{
  ArrayQueue<BinTreeNode<T>*> queue;
  BinTreeNode<T>* temp = t;
  while(temp != nullptr){
    if(temp->left != nullptr)
      queue.push(temp->left);
    if(temp->right != nullptr)
      queue.push(temp->right);
    visit(temp);
    if(queue.empty())
      break;
    temp = queue.pop();
  }
}

template<class T>
int LinkedBinaryTree<T>::height(BinTreeNode<T> *t) const
{
  if(t == nullptr)
    return 0;
  else{
    int hl = height(t->left); // 左子树的高度
    int hr = height(t->right); // 右子树的高度
    return hl >= hr ? ++hl: ++hr;
  }
}

template<class T>
BinTreeNode<T>* LinkedBinaryTree<T>::CopyCreatePreOrder(const BinTreeNode<T> *t)
{
  BinTreeNode<T> * new_p = nullptr;
  if(t != nullptr){
    new_p = new BinTreeNode<T>(t->element,
                               CopyCreatePreOrder(t->left),
                               CopyCreatePreOrder(t->right));
  }
  return new_p;
}

#endif

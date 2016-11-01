#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "linked_binary_tree.h"

#include <iostream>

using namespace std;

template<class K, class E>
class BSTree
{
 public:
  virtual ~BSTree() { }
  // 按键查找数对
  virtual pair<const K, E>* find(const K&) const = 0;
  // 插入
  virtual void insert(const pair<K, E>&) = 0;
  // 按关键字删除
  virtual void erase(const K&) = 0;
  // 按关键字的升序输出所有数对
  virtual void ascend() = 0;
};

template<class K, class E>
class BinarySearchTree: public BSTree<K, E>,
public LinkedBinaryTree<pair<K, E>>
{
 public:
  pair<const K, E>* find(const K&);
  void insert(const pair<K, E>&);
  void erase(const K&);
  void ascend();
};

template<class K, class E>
pair<const K, E>* BinarySearchTree<K, E>::find(const K&)
{
}


#endif

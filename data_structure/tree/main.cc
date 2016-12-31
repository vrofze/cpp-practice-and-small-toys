//stack test main.cc
//frost

#include "linked_binary_tree.h"
#include <iostream>

int main()
{
  LinkedBinaryTree<char> tree;
  tree.MakeTree();
  tree.PreOrderOutput();
  tree.InOrder(LinkedBinaryTree<char>::Output);
  std::cout << std::endl;
  tree.PostOrder(LinkedBinaryTree<char>::Output);
  std::cout << std::endl;
  tree.LevelOrder(LinkedBinaryTree<char>::Output);
  std::cout << std::endl;
  std::cout << "copy" << std::endl;
  LinkedBinaryTree<char> new_tree(tree);
  new_tree.PreOrderOutput();
  tree.PreOrder_f();
  std::cout << std::endl;
  tree.InOrder_f();
  std::cout << std::endl;
  tree.PostOrder_f();
  std::cout << std::endl;
  return 0;
}

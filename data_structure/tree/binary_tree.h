#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "bin_tree_node.h"
#include <iostream>

template<class T>
class BinaryTree
{
public:
    virtual ~BinaryTree() { }
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;

    // 二叉树的操作均基于遍历
    // 参数为int (*) (T*)函数指针,通过遍历执行操作
    /**
       preorder visit the tree
       @verbatim
       root --> left --> right
       @endverbatim
    */
    virtual void PreOrder(void (*) (T *)) = 0; //前序遍历
    /**
       visit the tree with inorder
       @verbatim
       left --> root --> right
       @endverbatim
    */
    virtual void InOrder(void (*) (T *)) = 0; // 中序遍历
    /**
       visit the tree with post order
       @verbatim
       left --> right --> root
       @endverbatim
    */
    virtual void PostOrder(void (*) (T *)) = 0; // 后序遍历
    /**
       visit the tree with level order
       @verbatim
       level: top --> bottom
       @endverbatim
    */
    virtual void LevelOrder(void (*) (T *)) = 0; // 层次遍历
};

#endif

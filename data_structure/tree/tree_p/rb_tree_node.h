#ifndef BIN_TREE_NODE_P_H
#define BIN_TREE_NODE_P_H

enum COLOR {RED, BLACK };

template<class T>
struct RBTreeNode
{
    T element;
    RBTreeNode<T> *left, *right, *p;
    COLOR color;
    RBTreeNode()
        {
            left = right = p = nullptr;
            color = COLOR::BLACK;
        }
    RBTreeNode(const T& t): element(t)
        {
            left = right = p = nil;
        }
    RBTreeNode(const RBTreeNode& node): element(node.element), left(node.left), right(right), p(p), color(color)
        { }
    RBTreeNode(const T element, RBTreeNode<T> *left, RBTreeNode<T> *right, RBTreeNode<T> *p):element(element), left(left), right(right), p(p)
        { }
    RBTreeNode(const T element, RBTreeNode<T> *left, RBTreeNode<T> *right, RBTreeNode<T> *p, COLOR color): element(element), left(left), right(right), p(p), color(color)
        { }

    static RBTreeNode *nil;
};

template<class T>
RBTreeNode<T> *RBTreeNode<T>::nil = new RBTreeNode<T>();

#endif

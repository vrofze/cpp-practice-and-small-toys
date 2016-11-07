#ifndef BIN_TREE_NODE_H
#define BIN_TREE_NODE_H

template<class T>
struct BinTreeNode
{
    T element;
    BinTreeNode<T> *left, *right;
    BinTreeNode()
        {
            left = right = nullptr;
        }
    BinTreeNode(const T& t): element(t)
        {
            left = right = nullptr;
        }
    BinTreeNode(const BinTreeNode& node): element(node.element)
        {
            left = node.left;
            right = node.right;
        }
    BinTreeNode(const T element, BinTreeNode<T> * left, BinTreeNode<T>* right):element(element)
        {
            this->left = left;
            this->right = right;
        }
};

#endif

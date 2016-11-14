#ifndef BIN_TREE_NODE_P_H
#define BIN_TREE_NODE_P_H

template<class T>
struct BinTreeNode
{
    T element;
    BinTreeNode<T> *left, *right, *p;
    BinTreeNode()
        {
            left = right = p = nullptr;
        }
    BinTreeNode(const T& t): element(t)
        {
            left = right = p = nullptr;
        }
    BinTreeNode(const BinTreeNode& node): element(node.element)
        {
            left = node.left;
            right = node.right;
            p = node.p;
        }
    BinTreeNode(const T element, BinTreeNode<T> *left, BinTreeNode<T> *right, BinTreeNode<T> *p): element(element)
        {
            this->left = left;
            this->right = right;
            this->p = p;
        }
};

#endif

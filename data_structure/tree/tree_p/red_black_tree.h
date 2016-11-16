#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include "linked_binary_tree_p.h"
#include "rb_tree_node.h"

#include <iostream>

using namespace std;

template<class K, class E>
class RedBlackTree: public LinkedBinaryTree<pair<const K, E>>
{
public:
    const pair<const K, E>& search(const K&) const;
    const pair<const K, E>& minimum() const
        {
            return minimum(this->root);
        }
    const pair<const K, E>& maximum() const
        {
            return maximum(this->root);
        }
    const pair<const K, E>& successor() const;
    const pair<const K, E>& predecessor() const;
    void insert(const pair<const K, E>&);
    void tree_delete(const K&);

private:
    const pair<const K, E>& minimum(RBTreeNode<pair<const K, E>> *) const;
    const pair<const K, E>& maximum(RBTreeNode<pair<const K, E>> *) const;
    void transplant(RBTreeNode<pair<const K, E>> *,
                    RBTreeNode<pair<const K, E>> *);
};

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::search(const K& key) const
{
    RBTreeNode<pair<const K, E>> *p = this->root;
    while(key != nullptr && key != p->element.first){
        if(key < p->element.first)
            p = p->left;
        else
            p = p->right;
    }
    return p->element;
}

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::minimum(RBTreeNode<pair<const K, E>> *p) const
{
    while(p->left != nullptr)
        p = p->left;
    return p->element;
}

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::maximum(RBTreeNode<pair<const K, E>> *p) const
{
    while(p->right != nullptr)
        p = p->right;
}

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::successor() const
{
    RBTreeNode<pair<const K, E>> *p = this->root;
}
#endif

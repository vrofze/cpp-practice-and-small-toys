#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "linked_binary_tree.h"
#include "bin_tree_node.h"

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
    void insert(const pair<const K, E>&);
    void erase(const K&);
    void ascend();
};

template<class K, class E>
pair<const K, E>* BinarySearchTree<K, E>::find(const K& key)
{
    BinTreeNode<pair<const K, E>> *p = this->root;

    while(p != nullptr){
        if(key < p->element.first)
            p = p->left;
        else if(key > p->element.first)
            p = p->right;
        else
            return &p->element;
    }
}

template<class K, class E>
void BinarySearchTree<K, E>::insert(const pair<const K, E>& the_pair)
{
    BinTreeNode<pair<const K, E>> *p = this->root,
        *pp = nullptr;
    while(p != nullptr){
        pp = p;
        if(the_pair.first < p->element.first)
            p = p->left;
        else if(the_pair.first > p->element.frist)
            p = p->right;
        else {
            p->element.second = the_pair.second;
            return;
        }
    }

    BinTreeNode<pair<const K, E>> *new_node
        = new BinTreeNode<pair<const K, E>>(the_pair);
    if(this->root != nullptr)
        if(the_pair.first < pp->element.first)
            pp->left = new_node;
        else
            pp->right = new_node;
    else
        pp = new_node;
    ++this->tree_size;
}

template<class K, class E>
    void BinarySearchTree<K, E>::erase(const K& the_key)
{
    BinTreeNode<pair<const K, E>> *p = this->root,
        *pp = nullptr;
    while(p != nullptr && p->element.first != the_key){
        pp = p;
        if(the_key < p->element.first)
            p = p->left;
        else
            p = p->right;
    }
    if(p == nullptr)
        return ;

    if(p->left != nullptr && p->right != nullptr){
        BinTreeNode<pair<const K, E>> *s = p->left,
            *ps = p;

        while(s->right != nullptr){
            ps = s;
            s = s->right;
        }

        BinTregeNode<pair<const K, E>> *q =
            new BinTreeNode<pair<const K, E>>(s->element, s->left, s->right);
        if(pp == nullptr) // root 为空
            root = q;
        else if(p == pp->left)
    }
}


#endif

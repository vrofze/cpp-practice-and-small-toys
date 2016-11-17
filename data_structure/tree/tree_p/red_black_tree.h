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
    typedef RBTreeNode<pair<const K, E>> Node;
    const pair<const K, E>& search(const K&) const;
    const pair<const K, E>& minimum() const
        {
            return minimum(this->root);
        }
    const pair<const K, E>& maximum() const
        {
            return maximum(this->root);
        }
    const pair<const K, E>& successor(const K&) const;
    const pair<const K, E>& predecessor(const K&) const;
    void insert(const pair<const K, E>&);
    void tree_delete(const K&);

private:
    const pair<const K, E>& minimum(Node *) const;
    const pair<const K, E>& maximum(Node *) const;
    void transplant(Node *, Node *);
    Node* find(const K& key) const;
    void left_rotate(Node *);
    void right_rotate(Node *);
    void insert_fixup(Node *);
    void delete_fixup(Node *);
};

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::search(const K& key) const
{
    RBTreeNode<pair<const K, E>> *p = this->root;
    while(key != Node::nil && key != p->element.first){
        if(key < p->element.first)
            p = p->left;
        else
            p = p->right;
    }
    return p->element;
}

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::minimum(Node *p) const
{
    while(p->left != Node::nil)
        p = p->left;
    return p->element;
}

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::maximum(Node *p) const
{
    while(p->right != Node::nil)
        p = p->right;
}

template<class K, class E>
typename RedBlackTree<K, E>::Node* RedBlackTree<K, E>::find(const K& key) const
{
    Node *p = this->root;
    while(p != Node::nil && key != p->element.first){
        if(key < p->element.first)
            p = p->left;
        else if(key > p->element.first)
            p = p->right;
    }
    return p;
}

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::successor(const K& key) const
{
    Node *p = find(key);
    if(p == Node::nil)
        return pair<const K, E>();
    if(p->right != Node::nil)
        return minimum(p->right);
    Node *p_su = p->p;
    while(p_su != Node::nil && p_su != p->left){
        p = p_su;
        p_su = p->p;
    }
    return p_su;
}

template<class K, class E>
const pair<const K, E>& RedBlackTree<K, E>::predecessor(const K& key) const
{
    Node *p = find(key);
    if(p == Node::nil)
        return pair<const K, E>();
    if(p->left != Node::nil)
        return maximum(p->left);
    Node *p_pre = p->p;
    while(p_pre != Node::nil && p_pre != p->right){
        p = p_pre;
        p_pre = p_pre->p;
    }
    return p_pre;
}

template<class K, class E>
void RedBlackTree<K, E>::insert(const pair<const K, E>& pair)
{
    Node *p = find(pair.first);
    Node *new_node = new Node(pair);
    new_node->color = COLOR::RED; // make new node red;
    if(p->p == Node::nil)
        this->root = new_node;
    else if(p == p->p->left)
        p->p->left = new_node; // new node should be placed in left child
    else p->p->right = new_node; // new node should be placed in right child
    insert_fixup(new_node); // fixup insert
}

template<class K, class E>
void RedBlackTree<K, E>::insert_fixup(Node *z)
{
    while(z->p->color == COLOR::RED){
        if(z->p == z->p->p->left){
            Node *y = z->p->p->right;
            if(y->color == COLOR::RED){
                z->p->color = COLOR::BLACK;
                y->color = COLOR::BLACK;
                z->p->p->color = COLOR::RED;
                z = z->p->p;
            }
            else {
                if(z == z->p->right){
                    z = z->p;
                    left_rotate(z);
                }
                z->p->color = COLOR::BLACK;
                z->p->p->color = COLOR::RED;
                right_rotate(z->p->p);
            }
        }
    }
}

template<class K, class E>
void RedBlackTree<K, E>::transplant(Node *old_p, Node *new_p)
{
    if(old_p->p == Node::nil)
        this->root = new_p;
    else if(old_p == old_p->p->left)
        old_p->p->left = new_p;
    else old_p->p->right = new_p;
    new_p->p = old_p->p;
}

template<class K, class E>
void RedBlackTree<K, E>::tree_delete(const K& key)
{
    Node *p = find(key);
    if(p == Node::nil)
        return ;
    if(p->left == Node::nil)
        transplant(p, p->right);
    else if(p->right == Node::nil)
        transplant(p, p->left);
    else {
        Node *min = minimum(p->right);
        if(min != p){
            transplant(min, min->right);
            min->right = p->right;
            min->right->p = min;
        }
        transplant(p, min);
        min->left = p->left;
        min->right->p = p;
    }
}

template<class K, class E>
void RedBlackTree<K, E>::left_rotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if(y->left != Node::nil)
        x->right->p = x;
    y->p = x->p;
    if(x->p == Node::nil)
        this->root = y;
    else if(x == x->p->left)
        x->p->left = y;
    else x->p->right = y;
    y->left = x;
    x->p = y;
}

template<class K, class E>
void RedBlackTree<K, E>::right_rotate(Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    if(x->right != Node::nil)
        y->right->p = y;
    x->p = y->p;
    if(y->p == Node::nil)
        this->root = x;
    else if(y == y->p->left)
        y->p->left = x;
    else y->p->right = x;
    x->right = y;
    y->p = x;
}

#endif

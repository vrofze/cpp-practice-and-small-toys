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
    Node *p = this->root, *y;
    while(p != Node::nil && pair.first != p->element.first){
        y = p;
        if(pair.first < p->element.first)
            p = p->left;
        else if(pair.first > p->element.first)
            p = p->right;
    }

    // make a new node
    Node *new_node = new Node(pair, Node::nil, Node::nil, y, COLOR::RED);
    if(y == Node::nil){
        this->root = new_node;
    }
    else if(pair.first < y->element.first)
        y->left = new_node; // new node should be placed in left child
    else
        y->right = new_node; // new node should be placed in right child
    insert_fixup(new_node); // fixup insert
    ++this->tree_size;
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
        else {
            Node *y = z->p->p->left;
            if(y->color == COLOR::RED){
                z->p->color = COLOR::BLACK;
                y->color = COLOR::BLACK;
                z->p->p->color = COLOR::RED;
                z = z->p->p;
            }
            else {
                if(z == z->p->right){
                    z = z->p;
                    right_rotate(z);
                }
                z->p->color = COLOR::BLACK;
                z->p->p->color = COLOR::RED;
                left_rotate(z->p->p);
            }
        }
    }
    this->root->color = COLOR::BLACK;
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
    Node *y = z, x;
    COLOR y_original_color = y->color; // y_original_color save the lost color
    if(z == Node::nil)
        return ;
    if(z->left == Node::nil){
        x = z->right;
        transplant(z, z->right);
    }
    else if(z->right == Node::nil){
        x = z->left;
        transplant(z, z->left);
    }
    else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if(y != z){
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
        delete z;                     // free
    }
    if(y_original_color == COLOR::BLACK)
        delete_fixup(x);
    --this->tree_size;
}

template<class K, class E>
void RedBlackTree<K, E>::delete_fixup(Node *x)
{
    while(x != this->root && x->color == COLOR::BLACK){
        if(x == x->p->left){
            Node *w = x->p->right;
            if(w->color == COLOR::RED){
                w->color = COLOR::BLACK;
                x->p->color = COLOR::RED;
                left_rotate(x->p);
                w = x->p->right;
            }
            if(w->left->color == COLOR::BLACK &&
               w->right->color == COLOR::BLACK){
                w->color = COLOR::RED;
                x = x->p;
            }
            else {
                if(w->right->color == COLOR::BLACK){
                    w->left->color = COLOR::BLACK;
                    w->right->color = COLOR::RED;
                    right_rotate(w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = COLOR::BLACK;
                w->right->color = COLOR::BLACK;
                left_rotate(x->p);
                x = this->root;
            }
        }
        else {                                        // x == x->p->right
            Node *w = x->p->left;
            if(w->color == COLOR::RED){
                w->color = COLOR::BLACK;
                w->p->color = COLOR::RED;
                right_rotate(w->p);
                w = w->p->left;
            }
            if(w->left->color == COLOR::BLACK &&
               w->right->color == COLOR::BLACK){
                w->color = COLOR::BLACK;
                x = x->p;
            }
            else {
                if(w->left->color == COLOR::BLACK){
                    w->right->color = COLOR::BLACK;
                    w->color = COLOR::RED;
                    left_rotate(w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = COLOR::BLACK;
                w->left->color = COLOR::BLACK;
                right_rotate(x->p);
                x = this->root;
            }
        }
    }
    x->color = COLOR::BLACK;
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

template<class K, class E>
ostream& operator<<(ostream& out, const pair<const K, E> pair)
{
    out << "<" << pair.first << ", " << pair.second << "> ";
}

#endif

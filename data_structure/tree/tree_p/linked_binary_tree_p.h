#ifndef LINKED_BINARY_TREE_P_H
#define LINKED_BINARY_TREE_P_H

#include "rb_tree_node.h"
#include "../../queue/array_queue.h"

#include <iostream>

template<class T>
class LinkedBinaryTree
{
public:
    LinkedBinaryTree()
        {
            root = RBTreeNode<T>::nil;
            tree_size = 0;
        }
    LinkedBinaryTree(const LinkedBinaryTree<T>& tree)
        {
            this->root = CopyCreatePreOrder(tree.root);
        }
   ~LinkedBinaryTree() { erase(); }


    bool empty() const { return tree_size == 0; }
    size_t size() const { return tree_size; }
    void MakeTree();
    void PreOrder(void (*visit)(RBTreeNode<T> *))
        {
            PreOrder(visit, root);
        }

    void InOrder(void (*visit)(RBTreeNode<T> *))
        {
            InOrder(visit, root);
        }

    void PostOrder(void (*visit)(RBTreeNode<T> *))
        {
            PostOrder(visit, root);
        }

    void LevelOrder(void (*visit)(RBTreeNode<T> *))
        {
            LevelOrder(visit, root);
        }

    void erase()
        {
            PostOrder(dispose); // delete node with post order
        }

    void PreOrderOutput()
        {
            PreOrder(Output);
            std::cout << std::endl;
        }

    static void Output(RBTreeNode<T> *t)
        {
            std::cout << t->element << " ";
        }


    int height() const { return height(root); }

protected:
    RBTreeNode<T>* root;
    size_t tree_size;
    static void PreOrder(void (*)(RBTreeNode<T> *), RBTreeNode<T> *);
    static void InOrder(void (*)(RBTreeNode<T> *), RBTreeNode<T> *);
    static void PostOrder(void (*)(RBTreeNode<T> *), RBTreeNode<T> *);
    static void LevelOrder(void (*)(RBTreeNode<T> *), RBTreeNode<T> *);
    static void dispose(RBTreeNode<T> *t) { delete t; }; // delete node
    int height(RBTreeNode<T> *) const;

    RBTreeNode<T>* CopyCreatePreOrder(const RBTreeNode<T> *);

};

template<class T>
void LinkedBinaryTree<T>::MakeTree()
{
    root = new RBTreeNode<T>('+', RBTreeNode<T>::nil,
                             RBTreeNode<T>::nil, RBTreeNode<T>::nil);
    root->left = new RBTreeNode<T>('*', RBTreeNode<T>::nil,
                                   RBTreeNode<T>::nil, root);
    root->left->left = new RBTreeNode<T>('a', RBTreeNode<T>::nil,
                                         RBTreeNode<T>::nil, root->left);
    root->left->right = new RBTreeNode<T>('b', RBTreeNode<T>::nil,
                                          RBTreeNode<T>::nil, root->left);
    root->right = new RBTreeNode<T>('/', RBTreeNode<T>::nil,
                                    RBTreeNode<T>::nil, root);
    root->right->left = new RBTreeNode<T>('c', RBTreeNode<T>::nil,
                                          RBTreeNode<T>::nil, root->right);
    root->right->right = new RBTreeNode<T>('d', RBTreeNode<T>::nil,
                                           RBTreeNode<T>::nil, root->right);
    tree_size = 7;
}

template<class T>
void LinkedBinaryTree<T>::PreOrder(void (*visit)(RBTreeNode<T> *), RBTreeNode<T> *t)
{
    if(t != RBTreeNode<T>::nil){
        visit(t);
        PreOrder(visit, t->left);
        PreOrder(visit, t->right);
    }
}

template<class T>
void LinkedBinaryTree<T>::InOrder(void (*visit)(RBTreeNode<T> *), RBTreeNode<T> *t)
{
    if(t != RBTreeNode<T>::nil){
        InOrder(visit, t->left);
        visit(t);
        InOrder(visit, t->right);
    }
}

template<class T>
void LinkedBinaryTree<T>::PostOrder(void (*visit)(RBTreeNode<T> *), RBTreeNode<T> *t)
{
    if(t != RBTreeNode<T>::nil){
        PostOrder(visit, t->left);
        PostOrder(visit, t->right);
        visit(t);
    }
}

template<class T>
void LinkedBinaryTree<T>::LevelOrder(void (*visit)(RBTreeNode<T> *), RBTreeNode<T> *t)
{
    ArrayQueue<RBTreeNode<T>*> queue;
    RBTreeNode<T>* temp = t;
    while(temp != RBTreeNode<T>::nil){
        if(temp->left != RBTreeNode<T>::nil)
            queue.push(temp->left);
        if(temp->right != RBTreeNode<T>::nil)
            queue.push(temp->right);
        visit(temp);
        if(queue.empty())
            break;
        temp = queue.pop();
    }
}

template<class T>
int LinkedBinaryTree<T>::height(RBTreeNode<T> *t) const
{
    if(t == RBTreeNode<T>::nil)
        return 0;
    else{
        int hl = height(t->left); // 左子树的高度
        int hr = height(t->right); // 右子树的高度
        return hl >= hr ? ++hl: ++hr;
    }
}

template<class T>
RBTreeNode<T>* LinkedBinaryTree<T>::CopyCreatePreOrder(const RBTreeNode<T> *t)
{
    RBTreeNode<T> * new_p = RBTreeNode<T>::nil;
    if(t != RBTreeNode<T>::nil){
        new_p = new RBTreeNode<T>(t->element,
                                  CopyCreatePreOrder(t->left),
                                  CopyCreatePreOrder(t->right),
                                  t->p,
                                  t->color);
    }
    return new_p;
}

#endif

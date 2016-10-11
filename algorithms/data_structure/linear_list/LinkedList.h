#ifndef LINKLIST_H
#define LINKLIST_H

#include "LinearList.h"

template<typename T>
struct LinkNode
{
  T element;

  LinkNode *next;

  LinkNode() { }
  LinkNode(const T& element) {
    this->element = element;
    this->next = nullptr;
  }
  LinkNode(const T& element, LinkNode<T> * next){
    this->element = element;
    this->next = next;
  }
  LinkNode(const LinkNode& node)
  {
    this->element = node.element;
    this->next = node.next;
  }
};

template<typename T>
class LinkedList : public LinearList<T>
{
 public:
  LinkedList(const LinkedList&);
  ~LinkedList();

  bool empty() const { return list_size == 0; };
  int size() const { return list_size; };
  T& get(int) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;


 protected:
  void checkIndex(int theIndex) const;
  LinkNode<T>* header;
  int list_size;
};



#endif

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
  LinkedList();
  LinkedList(const LinkedList&);
  ~LinkedList();

  bool empty() const { return list_size == 0; };
  int size() const { return list_size; };
  T& get(int) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;
  void push_back(const T& theElement);


 protected:
  void checkIndex(int theIndex) const;
  LinkNode<T>* header;
  size_t list_size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
  header = nullptr;
  list_size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
  list_size = list.list_size;

  LinkNode<T>* source_node = list.header;
  header = new LinkNode<T>(source_node);
  LinkNode<T>* taget_node = header;
  do{
    LinkNode<T> taget_node = new LinkNode<T>(*source_node);
    source_node = source_node->next;
  } while(taget_node != nullptr);
}

template<typename T>
LinkedList<T>::~LinkedList()
{
  while(header != nullptr){
    LinkNode<T>* next_node = header->next;
    delete header;
    header = next_node;
  }
}

template<typename T>
T& LinkedList<T>::get(int theIndex) const
{
  checkIndex(theIndex);
  LinkNode<T>* pnode = header;
  for(size_t i = 0; i != theIndex; ++i)
    pnode = pnode->next;
  return pnode->element;
}

template<typename T>
int LinkedList<T>::indexOf(const T& theElement) const
{
  if(header == nullptr)
    return -1;

  LinkNode<T>* pnode = header;
  int index = 0;
  while(pnode != nullptr && pnode->element != theElement){
    pnode = pnode->next;
    index++;
  }
  if(pnode == nullptr)
    return -1;
  else
    return index;
}

template<typename T>
void LinkedList<T>::erase(int theIndex)
{
  checkIndex(theIndex);

  LinkNode<T>* delete_node;
  if(list_size == 0){
    delete_node = header;
    header = header->next;
  } else {
    if(theIndex == 0){
      delete_node = header;
      header = header->next;
    }
    else{
      LinkNode<T>* pnode = header;
      for(size_t i = 0; i != theIndex - 1; i++)
        pnode = pnode->next;
      delete_node = pnode->next;
      pnode->next = pnode->next->next;
    }
  }
  list_size--;
  delete delete_node;
  delete_node = nullptr;
}

template<typename T>
void LinkedList<T>::insert(int theIndex, const T& theElement)
{
  checkIndex(theIndex);

  if(theIndex == 0){
    header = new LinkNode<T>(theElement, header);
  }
  else {
    LinkNode<T>* pnode = header;
    for(int i = 0; i < theIndex - 1; ++i)
      pnode = pnode->next;
    pnode->next = new LinkNode<T>(theElement, pnode->next);
  }
  ++list_size;
}

template<typename T>
void LinkedList<T>::output(std::ostream& out) const
{
  LinkNode<T>* pnode = header;
  for(size_t i = 0; i < list_size; ++i){
    out << pnode->element << " ";
    pnode = pnode->next;
  }
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
{
  list.output(out);
  return out;
}

template<typename T>
void LinkedList<T>::push_back(const T& theElement)
{
  if(list_size == 0){
    header = new LinkNode<T>(theElement, nullptr);
    ++list_size;
    return;
  }
  LinkNode<T>* pnode = header;
  for(size_t i = 0; i < list_size - 1; ++i)
    pnode = pnode->next;
  pnode->next = new LinkNode<T>(theElement, nullptr);
  ++list_size;
}

template<typename T>
void LinkedList<T>::checkIndex(int theIndex) const
{
  if(theIndex < 0 || theIndex > list_size)
    throw "the index out of range";
}



#endif

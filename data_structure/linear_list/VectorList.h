#ifndef VECTORLIST_H
#define VECTORLIST_H

#include "LinearList.h"
#include <vector>
#include <iterator>
#include <algorithm>

template<typename T>
class VectorList : public LinearList<T>
{
 public:
  VectorList(int length = 10);
  VectorList(const VectorList<T>&);
  ~VectorList() { delete element; }

  bool empty() const { return element->empty(); }
  int size() const { return (int) element->size(); }
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;

  void push_back(const T& theElement);

  int capacity() const { return (int) element->capacity(); }

  typedef typename std::vector<T>::iterator iterator;
  iterator begin() {return element->begin(); }
  iterator end() { return element->end(); }

 protected:
  void checkIndex(int theIndex) const;
  std::vector<T>* element;
};

template<typename T>
VectorList<T>::VectorList(int length)
{
  if(length < 1)
    throw "length must >= 1";

  element = new std::vector<T>;
  element->reserve(length);
}

template<typename T>
VectorList<T>::VectorList(const VectorList<T>& theList)
{
  element = new std::vector<T>(*theList.element);
}

template<typename T>
T& VectorList<T>::get(int theIndex) const
{
  if(theIndex < 0 || theIndex > element->size())
    throw "the index out of range";

  return (*element)[theIndex];
}

template<typename T>
void VectorList<T>::checkIndex(int theIndex) const
{
  if(theIndex < 0 || theIndex >= size()) throw "index out of range";
}

template<typename T>
int VectorList<T>::indexOf(const T& theElement) const
{
  int i = 0;
  auto it = element->begin();
  for(; it != element->end(); ++it)
    {
      if(*it == theElement) {
        return i;
      }
      ++i;
    }
  return -1;
}

template<typename T>
void VectorList<T>::erase(int theIndex)
{
  checkIndex(theIndex);
  element->erase(begin() + theIndex);
}

template<typename T>
void VectorList<T>::insert(int theIndex, const T& theElement)
{
  if(theIndex < 0 || theIndex > size())
    throw "theIndex out of range";

  element->insert(element->begin() + theIndex, theElement);
}

template<typename T>
void VectorList<T>::output(std::ostream& out) const
{
  std::copy(element->begin(), element->end(), std::ostream_iterator<T>(out, " "));
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const VectorList<T>& x)
{
  x.output(out);
  return out;
}

template<typename T>
void VectorList<T>::push_back(const T& theElement)
{
  element->push_back(theElement);
}

#endif

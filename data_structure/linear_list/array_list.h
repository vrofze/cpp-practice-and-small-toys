#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "linear_list.h"

#include <iostream>
#include <iterator>
#include <algorithm>

template<class T>
class iterator
{
public:
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& referrnce;

    iterator(T* thePosition) { position = thePosition; }

    T& operator*() const { return *position; }
    T& operator->() const { return &*position; }

    iterator& operator++()
        {++position; return *this; }
    iterator operator++(int)
        {iterator old = *this; ++position; return old; }

    iterator& operator--()
        {
            --position;
            return *this;
        }

    iterator operator--(int)
        {
            iterator old = *this;
            --position;
            return old;
        }

    bool operator!=(const iterator& rhs) const
        {
            return position != rhs.position;
        }

    bool operator==(const iterator& rhs) const
        {
            return position == rhs.position;
        }

protected:
    T* position;
};

template<class T>
class ArrayList: public LinearList<T>
{
public:
    ArrayList(int length = 10);
    ArrayList(const ArrayList<T>&);
    ~ArrayList() { delete[] element; }

    bool empty() const { return list_size == 0; }
    int size() const { return list_size; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;

    void push_back(const T& theElement);

    iterator<T> begin() { return iterator<T>(element); }
    iterator<T> end() { return iterator<T>(element + list_size); }

protected:
    void checkIndex(int theIndex) const;

    T* element;
    int length;
    int list_size;
};

template<class T>
ArrayList<T>::ArrayList(int length)
{
    if(length < 1) throw "length must >= 1";

    this->length = length;
    element = new T[length];
    list_size = 0;
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& list)
{
    length = list.length;
    list_size = list.size;
    element = new T[length];
    std::copy(list.element, list.element + list_size, element);
}

template<class T>
void ArrayList<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0 || theIndex >= list_size) throw "index out of range";
}

template<class T>
T& ArrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

template<class T>
int ArrayList<T>::indexOf(const T& theElement) const
{
    int theIndex = (int)(std::find(element, element + list_size, theElement) - element);
    if(theIndex == list_size)
        return -1;
    else
        return theIndex;
}

template<class T>
void ArrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);

    std::copy(element + theIndex + 1, element + list_size, element + theIndex);
    element[--list_size].~T();
}

template<class T>
void ArrayList<T>::insert(int theIndex, const T& ele)
{
    if(theIndex < 0 || theIndex > list_size)
        throw "the index out of range";
    if(list_size == length)
        throw "ArrayList length limited";

    std::copy_backward(element + theIndex, element + list_size, element + list_size + 1);
    element[theIndex] = ele;
    list_size++;
}

template<class T>
void ArrayList<T>::output(std::ostream & out) const
{
    std::copy(element, element + list_size, std::ostream_iterator<T>(out, " "));
}

template<class T>
std::ostream& operator<<(std::ostream& out, const ArrayList<T>& x)
{
    x.output(out);
    return out;
}

template<class T>
void ArrayList<T>::push_back(const T& theElement)
{
    if(list_size == length)
        throw "ArrayList length limited";

    element[list_size] = theElement;
    list_size++;
}


#endif

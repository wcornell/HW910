/* OrderedSet class */

#ifndef ORDEREDSET_H
#define ORDEREDSET_H
#include <iostream>
#include <sstream>

#define _ORDEREDSET__MAXSIZE 1000


template <typename T>
typedef T* TPointer;

template <typename T>
class OrderedSet {
public:
    OrderedSet()
        {elements_= DLList<T>;};
    int insert(TPointer x);
    TPointer removeFirst();
    int remove(int x);
    int len();
    
    std::string str();
    
private:
    TPointer *elements_;
    void _insertionSort();
};

#include "OrderedSet.hpp"
#endif // ORDEREDSET_H


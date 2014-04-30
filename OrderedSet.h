/* OrderedSet class 
====================
Maintains an ordered set of pointers to class with method id()
*/

#ifndef ORDEREDSET_H
#define ORDEREDSET_H
#include <iostream>
#include <sstream>
#include "DLList.h"

#define _ORDEREDSET__MAXSIZE 1000

template <typename T>
class OrderedSet {
public:
<<<<<<< HEAD
    OrderedSet(int maxsize=_ORDEREDSET__MAXSIZE){maxsize_=maxsize;};
    ~OrderedSet(){};
    int insert(T x);
    T removeFirst();
=======
    OrderedSet()
        {elements_= DLList<T>;};
    int insert(TPointer x);
    TPointer removeFirst();
>>>>>>> 55c0771c12720e70f73f2077c19b6f0e14baedc9
    int remove(int x);
    int len();
    
    std::string str();
    
private:
<<<<<<< HEAD
    int maxsize_;
    DLList<T> L;
=======
    TPointer *elements_;
    void _insertionSort();
>>>>>>> 55c0771c12720e70f73f2077c19b6f0e14baedc9
};

class EmptySet{};
class SetFull{};

#include "OrderedSet.hpp"
#endif // ORDEREDSET_H


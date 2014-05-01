/* OrderedSet class 
====================
Maintains an ordered set of pointers to class with method id()
*/

#ifndef ORDEREDSET_H
#define ORDEREDSET_H
#include <iostream>
#include <sstream>
#include "DLList.h"

#define _ORDEREDSET_EMPTYSET 5
#define _ORDEREDSET__MAXSIZE 1000

template <typename T>
class OrderedSet {
public:
    OrderedSet(int maxsize=_ORDEREDSET__MAXSIZE){maxsize_=maxsize;};
    ~OrderedSet(){};
    int insert(T x);
    T removeFirst();
    int remove(int x);
    int len();
    
    std::string str();
    
private:
    int maxsize_;
    DLList<T> L;
};

class EmptySet{};
class SetFull{};

#include "OrderedSet.hpp"
#endif // ORDEREDSET_H


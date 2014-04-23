#ifndef _DLLIST_H
#define _DLLIST_H

// Forward declarations and prototypes used in the classes below
#include <iostream>
#include <cstddef>

template <typename T>
class DLList;
template <typename T>
std::ostream& operator<< <T>(std::ostream& os, const DLList<T>& l);

template <typename T>
class Node<T> {
	friend class DLList;
public:
	Node(T item, Node * next = NULL, Node * prev = NULL)
		: item_(item), next_(next), prev_(prev) {}
private:
	T item_;
	Node * next_;
	Node * prev_;
};

class DLList<T> {
public:
	// Constructors
	DLList<T>()
		: head(NULL), tail(NULL), nextiter(NULL), size(0) {}
	DLList<T>(const DLList& from);

	// Destructor
	virtual ~DLList();

	// Member functions
	DLList<T>& operator=(const DLList<T>& from);
	int length() const { return size; }
	void append(const T& item);
	void insert(int index, const T& item);
	T pop(int index=-1);
	T& operator[](int index);
	std::string str() const;
	void resetForward() { nextiter = NULL; }
	T next();

private:
	Node * head;
	Node * tail;
	Node * nextiter;
	int size;
	void allocCopy(const DLList<T>& from);
	void dealloc();
	Node * _find(int index);
	int _delete(int index);

	// Non-member friends
	friend std::ostream& operator<<(std::ostream& os, const DLList& l);
};

// Auxiliary classes for throwing "exceptions" on violated preconditions
class IndexError { };
class StopIteration { };
class DeallocError { };
class AllocError { };

#include "DLList.hpp"
#endif

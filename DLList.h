// Forward declarations and prototypes used in the classes below

#include <iostream>
#include <cstddef>

class DLList;

std::ostream& operator<<(std::ostream& os, const DLList& l);


class Node {
	friend class DLList;
public:
	Node(int item, Node * next = NULL, Node * prev = NULL)
		: item_(item), next_(next), prev_(prev) {}
private:
	int item_;
	Node * next_;
	Node * prev_;
};

class DLList {
public:
	// Constructors
	DLList()
		: head(NULL), tail(NULL), nextiter(NULL), size(0) {}
	DLList(const DLList& from);

	// Destructor
	virtual ~DLList();

	// Member functions
	DLList& operator=(const DLList& from);
	int length() const { return size; }
	void append(const int& item);
	void insert(int index, const int& item);
	int pop(int index=-1);
	int& operator[](int index);
	std::string str() const;
	void resetForward() { nextiter = NULL; }
	int next();

private:
	Node * head;
	Node * tail;
	Node * nextiter;
	int size;
	void allocCopy(const DLList& from);
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

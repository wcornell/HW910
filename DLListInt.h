// Forward declarations and prototypes used in the classes below

class DLListInt;

std::ostream& operator<<(std::ostream& os, const DLListInt& l);
class IntNode {
	friend class DLListInt;
public:
	IntNode(int item, IntNode * next = NULL, IntNode * prev = NULL)
		: item_(item), next_(next), prev_(prev) {}
private:
	int item_;
	IntNode * next_;
	IntNode * prev_;
};

class DLListInt {
public:
	// Constructors
	DLListInt()
		: head(NULL), tail(NULL), nextiter(NULL), size(0) {}
	DLListInt(const DLListInt& from);

	// Destructor
	virtual ~DLListInt();

	// Member functions
	DLListInt& operator=(const DLListInt& from);
	int length() const { return size; }
	void append(const int& item);
	void insert(int index, const int& item);
	int pop(int index=-1);
	int& operator[](int index);
	std::string str() const;
	void resetForward() { nextiter = NULL; }
	int next();

private:
	IntNode * head;
	IntNode * tail;
	IntNode * nextiter;
	int size;
	void allocCopy(const DLListInt& from);
	void dealloc();
	IntNode * _find(int index);
	int _delete(int index);

	// Non-member friends
	friend std::ostream& operator<<(std::ostream& os, const DLListInt& l);
};

// Auxiliary classes for throwing "exceptions" on violated preconditions
class IndexError { };
class StopIteration { };

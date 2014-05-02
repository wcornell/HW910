#include <sstream>
#include "DLListInt.h"

using namespace std;


IntNode* DLListInt::_find(int index){
	// pre: -size<=index<size
	// post: return a pointer to the indexed node
	// Exception: IndexError
	IndexError e; //Create an IndexError object to throw
	if(index < 0){ //Allow for negative indeces by converting to positive
		index += size;
	}
	if(index > size or index < 0){ //if index out of range
		throw e; //throw exception object
	}
	IntNode* cur = head; //variable to hold pointer to current node
	for(int i = 0; i < index; i++){ //loop over nodes
		cur = cur->next_;
	}
	return cur; //return pointer to node
}

void DLListInt::insert(int index, const int& item){
	if(index == size){ //if inserting at end
		append(item); //append
		return;
	}
	if(index == 0){ //if inserting at beginning
		IntNode* newNode = new IntNode(item); //create new node
		newNode->next_ = head; //new nodes next becomes previous first
		head->prev_ = newNode; //previous head's first becomes new node
		head = newNode; //head points to new node
	}
	else{ //if inserting middle element
		IntNode* prev = _find(index -1); //find node before insert location
		IntNode* newNode = new IntNode(item,prev->next_,prev); //create new node with each appropriate parameter
		prev->next_ = newNode; //prev's next is set to the new node
		newNode->next_->prev_ = newNode; //next's prev is set to new node
	}
	size++; //increment size
}


int DLListInt::pop(int index){
	// post: return the indexed value and delete the corresponding node
	return _delete(index);
}

int& DLListInt::operator[](int index){
	IntNode* node = _find(index); //find node at index
	return node->item_; //return it's item
}

string DLListInt::str() const{
	ostringstream os;
	os << "[";
	IntNode* cur = head;
	if(size > 0){
		os << cur->item_;
	}
	for(int i = 1; i < size; i++){
		cur = cur->next_;
		os << ", " << cur->item_;
	}
	os << "]";
	return os.str();
}

int DLListInt::next(){
	if (nextiter==tail){
		resetForward();
		throw StopIteration();
	}
	
	if (nextiter==NULL) nextiter=head;
	else nextiter = nextiter->next_;

	return nextiter->item_;
}

int DLListInt::_delete(int index){
	
	IntNode* nodeToDelete = _find(index);
	
	if (nodeToDelete==head) head = nodeToDelete->next_;
	if (nodeToDelete==tail) tail = nodeToDelete->prev_;
	
	
	if (nodeToDelete->prev_!=NULL) nodeToDelete->prev_->next_=nodeToDelete->next_;
	if (nodeToDelete->next_!=NULL) nodeToDelete->next_->prev_=nodeToDelete->prev_;
	
	
	
	int retval = nodeToDelete->item_;
	//delete nodeToDelete;
	size--;
	return retval;
}

DLListInt::DLListInt(const DLListInt& from)
	: head(NULL), tail(NULL), nextiter(NULL), size(0){
	// post: Construct DLListInt
	allocCopy(from);
}

DLListInt::~DLListInt(){
	// post: dealloc DLListInt
	dealloc();
}

DLListInt& DLListInt::operator=(const DLListInt& from){
	// post: assignment operator
	if (this != &from){ //if not self-assignment
		dealloc(); //deallocate storage
		allocCopy(from); //allocate new and copy to it
	}
	return *this; //return self
}

void DLListInt::allocCopy(const DLListInt& from){
	// post: allocate storage for the current DLListInt using information from the other DLListInt "from"
	AllocError e; //create error object to be thrown
	IntNode* cur = from.head; //pointer to current node, starting at from's head
	head = new IntNode(cur->item_); //create new node pointed to by head and copy to it
	
	IntNode* mycur = head; //pointer to this object's current node
	for (int i=0;i<from.size-1;i++){ //loop over nodes
		cur = cur->next_; //advance curr
		mycur->next_ = new IntNode(cur->item_,NULL,mycur); 
		mycur = mycur->next_;
		size++;
	}
	tail = mycur;
	if (++size!=from.size) throw e;
}

void DLListInt::append(const int& item){
	// post: append the item into the current list
	IntNode* newNode = new IntNode(item,NULL,tail); //create new node with prev of tail
	
	if (size==0){ //if no other nodes
		head = newNode; //head points to new node
		tail = newNode; //tail points to new node
		size++; //increment size
		return; 
	}
	
	tail->next_ = newNode; //tail's next becomes new node
	tail = newNode; //new node becomes tail
	size++; //increment size
}

void DLListInt::dealloc(){
	// post: dealloc the DLListInt
	// Exception: DeallocError if the last element to dealloc is not tail, or if dealloc different number of nodes than size
	DeallocError e; //create error object
	if (size==0) return; //if no nodes, return
	IntNode* cur = head; //pointer to the current node, starting from head
	int delsize = 0; //variable to track how many nodes have been deleted
	while (cur->next_!=NULL){ //while there are more nodes
		cur = cur->next_; //advance cur
		delete cur->prev_; //delete previous cur
		delsize++; //increment delsize
	}
	if (cur!=tail) throw e; //if not at last node, throw exception
	delete cur; //delete tail
	delsize++; //increment delsize
	if (delsize!=size) throw e; //if deleted is no equal to size, throw exception
	head = tail = NULL; //head and tail become null
	size = 0; //size becomes zero
}

ostream& operator<<(ostream& os, const DLListInt& l){
	os << l.str(); //insert string representation into os
	return os; //return os
}








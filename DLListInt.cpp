#include <sstream>
#include "DLListInt.h"

using namespace std;


IntNode* DLListInt::_find(int index){
	// pre: -size<=index<size
	// post: return a pointer to the indexed node
	// Exception: IndexError
	IndexError e;
	if(index < 0){
		index += size;
	}
	if(index > size or index < 0){
		throw e;
	}
	IntNode* cur = head;
	for(int i = 0; i < index; i++){
		cur = cur->next_;
	}
	return cur;
}

void DLListInt::insert(int index, const int& item){
	if(index == size){
		append(item);
		return;
	}
	if(index == 0){
		IntNode* newNode = new IntNode(item);
		newNode->next_ = head;
		head->prev_ = newNode;
		head = newNode;
	}
	else{
		IntNode* prev = _find(index -1);
		IntNode* newNode = new IntNode(item,prev->next_,prev);
		prev->next_ = newNode;
		newNode->next_->prev_ = newNode;
	}
	size++;
}


int DLListInt::pop(int index){
	// post: return the indexed value and delete the corresponding node
	return _delete(index);
}

int& DLListInt::operator[](int index){
	IntNode* node = _find(index);
	return node->item_;
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
	if (this!=&from){
		dealloc();
		allocCopy(from);
	}
	return *this;
}

void DLListInt::allocCopy(const DLListInt& from){
	// post: allocate storage for the current DLListInt using information from the other DLListInt "from"
	AllocError e;
	IntNode* cur = from.head;
	head = new IntNode(cur->item_);
	
	IntNode* mycur = head;
	for (int i=0;i<from.size-1;i++){
		cur = cur->next_;
		mycur->next_ = new IntNode(cur->item_,NULL,mycur);
		mycur = mycur->next_;
		size++;
	}
	tail = mycur;
	if (++size!=from.size) throw e;
}

void DLListInt::append(const int& item){
	// post: append the item into the current list
	IntNode* newNode = new IntNode(item,NULL,tail);
	
	if (size==0){
		head = newNode;
		tail = newNode;
		size++;
		return;
	}
	
	tail->next_ = newNode;
	tail = newNode;
	size++;
}

void DLListInt::dealloc(){
	// post: dealloc the DLListInt
	// Exception: DeallocError if the last element to dealloc is not tail, or if dealloc different number of nodes than size
	DeallocError e;
	if (size==0) return;
	IntNode* cur = head;
	int delsize = 0;
	while (cur->next_!=NULL){
		cur = cur->next_;
		delete cur->prev_;
		delsize++;
	}
	if (cur!=tail) throw e;
	delete cur;
	delsize++;
	if (delsize!=size) throw e;
	head = tail = NULL;
	size = 0;
}

ostream& operator<<(ostream& os, const DLListInt& l){
	os << l.str();
	return os;
}








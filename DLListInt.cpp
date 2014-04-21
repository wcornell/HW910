#include <sstream>
#include "DLListInt.h"

using namespace std;

void DLListInt::insert(int index, const int& item){
	if(index == size){
		append(item);
		return;
	}
	IntNode* newNode = new IntNode(item);
	if(index == 0){
		newNode->next_ = head;
		head->prev_ = newNode;
		head = newNode;
		return;
	}
	else{
		IntNode* prev = _find(index -1);
		newNode->prev_ = prev;
		newNode->next_ = prev->next_;
		prev->next_ = newNode;
		newNode->next_->prev_ = newNode;
		return;
	}
}


int DLListInt::pop(int index){
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
	if (nextiter==NULL) resetForward();
	int retval = nextiter->item_;
	nextiter = nextiter->next_;
	return retval;
}

IntNode* DLListInt::_find(int index){
	IndexError e;
	if(index < 0){
		index += size;
	}
	if(index > size){
		throw e;
	}
	IntNode* curr = head;
	for(int i = 0; i < index; i++){
		curr = curr->next_;
	}
	return curr;
}

int DLListInt::_delete(int index){
	IntNode* last = _find(-1);
	int retval = last->item_;
	IntNode* newLast = last->prev_;
	newLast->next_ = NULL;
	head = newLast;
	size--;
	delete last;
	return retval;
}

DLListInt::DLListInt(const DLListInt& from){
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
}

void DLListInt::allocCopy(const DLListInt& from){
	// post: allocate storage for the current DLListInt using information from the other DLListInt "from"
	IntNode* cur = from.head;
	IntNode* mycur = head;
	head = new IntNode(cur->item_);
	for (int i=0;i<from.size-1;i++){
		cur = cur->next_;
		mycur->next_ = new IntNode(cur->item_,mycur);
		mycur->next_->prev_ = mycur;
	}
	tail = mycur;
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








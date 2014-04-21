#include "DLListInt.h"

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

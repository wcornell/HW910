#include <sstream>

using namespace std;

/* ===================== Constructor ===================== */
template <typename T>
DLList<T>::DLList(const DLList<T>& from)
	: head(NULL), tail(NULL), nextiter(NULL), size(0){
	// post: Construct DLList
	allocCopy(from);
}

template <typename T>
DLList<T>::~DLList(){
	// post: dealloc DLList
	dealloc();
}

template <typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& from){
	// post: assignment operator
	if (this != &from){ //if not self-assignment
		dealloc(); //deallocate storage
		allocCopy(from); //allocate new and copy to it
	}
	return *this; //return self
}

/* ====================== Public Methods ====================== */

template <typename T>
void DLList<T>::insert(int index, const T& item){
	// post: insert a Node with item at indexed
	
	if(index == size){ //if inserting at end
		append(item); //append
		return;
	}
	if(index == 0){ //if inserting at beginning
		Node<T>* newNode = new Node<T>(item); //create new node
		newNode->next_ = head; //new nodes next becomes previous first
		head->prev_ = newNode; //previous head's first becomes new node
		head = newNode; //head points to new node
	}
	else{ //if inserting middle element
		Node<T>* prev = _find(index -1); //find node before insert location
		Node<T>* newNode = new Node<T>(item,prev->next_,prev); //create new node with each appropriate parameter
		prev->next_ = newNode; //prev's next is set to the new node
		newNode->next_->prev_ = newNode; //next's prev is set to new node
	}
	size++; //increment size
}

template <typename T>
void DLList<T>::append(const T& item){
	// post: append the item into the current list
	Node<T>* newNode = new Node<T>(item,NULL,tail); //create new node with prev of tail
	
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

template <typename T>
T DLList<T>::pop(int index){
	// post: return the indexed value and delete the corresponding node
	return _delete(index);
}

template <typename T>
string DLList<T>::str() const{
	ostringstream os;
	os << "[";
	Node<T>* cur = head;
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

template <typename T>
T DLList<T>::next(){
	if (nextiter==tail){
		resetForward();
		throw StopIteration();
	}
	
	if (nextiter==NULL) nextiter=head;
	else nextiter = nextiter->next_;

	return nextiter->item_;
}

/* ===================== Private Methods ===================== */
template <typename T>
Node<T>* DLList<T>::_find(int index){
	// pre: -size<=index<size
	// post: return a pointer to the indexed node
	// Exception: IndexError
	if(index < 0){ //Allow for negative indeces by converting to positive
		index += size;
	}
	if(index > size or index < 0){ //if index out of range
		throw IndexError(); //throw exception object
	}
	Node<T>* cur = head; //variable to hold pointer to current node
	for(int i = 0; i < index; i++){ //loop over nodes
		cur = cur->next_;
	}
	return cur; //return pointer to node
}

template <typename T>
T DLList<T>::_delete(int index){
	
	Node<T>* nodeToDelete = _find(index);
	
	if (nodeToDelete==head) head = nodeToDelete->next_;
	if (nodeToDelete==tail) tail = nodeToDelete->prev_;
	
	
	if (nodeToDelete->prev_!=NULL) nodeToDelete->prev_->next_=nodeToDelete->next_;
	if (nodeToDelete->next_!=NULL) nodeToDelete->next_->prev_=nodeToDelete->prev_;
	
	T retval = nodeToDelete->item_;
	size--;
	return retval;
}

template <typename T>
void DLList<T>::allocCopy(const DLList<T>& from){
	// post: allocate storage for the current DLList using information from the other DLList "from"
	Node<T>* cur = from.head; //pointer to current node, starting at from's head
	head = new Node<T>(cur->item_); //create new node pointed to by head and copy to it
	
	Node<T>* mycur = head; //pointer to this object's current node
	for (int i=0;i<from.size-1;i++){ //loop over nodes
		cur = cur->next_; //advance curr
		mycur->next_ = new Node<T>(cur->item_,NULL,mycur); 
		mycur = mycur->next_;
		size++;
	}
	tail = mycur;
	if (++size!=from.size) throw AllocError();
}

template <typename T>
void DLList<T>::dealloc(){
	// post: dealloc the DLList
	// Exception: DeallocError if the last element to dealloc is not tail, or if dealloc different number of nodes than size
	if (size==0) return; //if no nodes, return
	Node<T>* cur = head; //pointer to the current node, starting from head
	int delsize = 0; //variable to track how many nodes have been deleted
	while (cur->next_!=NULL){ //while there are more nodes
		cur = cur->next_; //advance cur
		delete cur->prev_; //delete previous cur
		delsize++; //increment delsize
	}
	if (cur!=tail) throw DeallocError(); //if not at last node, throw exception
	delete cur; //delete tail
	delsize++; //increment delsize
	if (delsize!=size) throw DeallocError(); //if deleted is no equal to size, throw exception
	head = tail = NULL; //head and tail become null
	size = 0; //size becomes zero
}
/* ===================== Operators ===================== */

template <typename T>
T& DLList<T>::operator[](int index){
	Node<T>* node = _find(index); //find node at index
	return node->item_; //return it's item
}

template <typename T>
ostream& operator<<(ostream& os, const DLList<T>& l){
	os << l.str(); //insert string representation into os
	return os; //return os
}


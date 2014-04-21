void DLListInt::insert(int index, const int& item){
	if(index == size){
		append(item);
		return;
	}
	IntNode newNode(item);
	if(index == 0){
		newNode.next_ = head;
		head->prev_ = newNode;
		head = newNode;
		return;
	}
	else{
		IntNode* prev = find_(index -1);
		newNode.prev_ = prev;
		newNode.next_ = prev->next_;
		prev->next_ = newNode;
		newNode.next_->prev_ = newNode;
		return;
	}


int DLListInt::pop(){
	return _delete(-1);
}

int& DLListInt::operator[](int index){
	IntNode* node = find_(index);
	return node->item_;
}

std::string DLListInt::str(){
	std::ostringstream str;
	str << "[";
	if(size > 0){
		str << (*this)[0];
	}
	for(int i = 1; i < size; i++){
		str << ", " << (*this)[i];
	}
	str << "]";
	return str.str();
}

int DLListInt::next(){
	int retval = nextiter->intem_;
	nextiter = nextiter->next_;
	return retval;
}

IntNode* DLListInt::find_(int index){
	if(index < 0){
		index += size;
	}
	if(index > size){
		throw IndexError;
	}
	IntNode* curr = head;
	for(int i = 0; i < index; i++){
		curr = curr->next_;
	}
	return curr;
}

int DLListInt::_delete(int index){
	ListNode* last = find_(-1);
	ListNode* newLast = last->prev_;
	newLast->next_ = NULL;
	head = newLast;
	size--;
	delete last;
	return;
}











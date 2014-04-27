using namespace std;

int OrderedSet::insert(EPointer newEvent){
	// pre: x is of comparable type with the rest of the set
	// post: x is inserted while maintaining order of the set. If x compares equal with other elements, it will be the last of such elements. If x is identical with another element, it will not be inserted. If insertion is successful the function returns 1, otherwise it returns 0.
	// Exception: _ORDEREDSET__SETFULL if set is full

	// special case: size_==0
	
    if (size_==0){
        elements_[0]=newEvent;
        size_++;
        return 1;
    }
    // stop insertion if set is full
    if (size_==maxsize_) return 0;
    // do not insert replica
    for (int i=0;i<size_;i++){
    	if (elements_[i]->id()==newEvent->id())
    		remove(elements_[i]->id());
    }
    
    // figure out index
    int idxToInsert=0; // insert at front if newEvent is smallest
    
    if (size_==1){
		if (*elements_[0]<=*newEvent){
			idxToInsert = 1;
    	}
    } else { // size_ > 1
		for (int i=size_-1;i>0;i--){
			if (elements_[i]<=newEvent){ // insert in the middle if newEvent is not smallest
				idxToInsert = i+1;
				break;
			}
		}
	}
	
    // perform insertion
    elements_[size_++] = newEvent;
    for (int i=size_-2;i>=idxToInsert;i--){
    	swap(elements_[i],elements_[i+1]);
    }  		 
    
    return 1;
}

EPointer OrderedSet::removeFirst(){
	// pre: set should not be full
	// post: the first element in the set is removed and returned 
	// Exception: throw _ORDEREDSET__EMPTYSET
	if (size_==0) throw _ORDEREDSET__EMPTYSET;
	EPointer firstEvent;
	firstEvent = elements_[0];
	for (int i=1;i<size_;i++) elements_[i-1]=elements_[i];
	size_--;
	return firstEvent;
}

int OrderedSet::remove(int x){
	// post: remove the event with id x and return 1, or return 0 if its not found
	for (int i=0;i<size_;i++){
		if ( elements_[i]->id()==x ){
			for (int j=i;j<size_-1;j++){
				elements_[j] = elements_[j+1];
			}
			size_--;
			return 1;
		}
	}
	return 0;
}

string OrderedSet::str(){
	// post: returns the string representation of OrderedSet
    stringstream os;
    if (size_==0){
		os << "[]";
		return os.str();
    }
    if (size_ ==1){
    	os << "[" << elements_[0]->str() << "*]";
    	return os.str();
    }
    os << "[";
    for (int i=0;i<size_-1;i++){
    	os << elements_[i]->str();
    	if (i==0) os << "*";
    	os << ", ";
    }
    os << elements_[size_-1]->str() << "]";
    return os.str();
}

int OrderedSet::len(){return size_;}


using namespace std;

template <typename T>
int OrderedSet::insert(TPointer newT){
	// pre: x is of comparable type with the rest of the set
	// post: x is inserted while maintaining order of the set. If x compares equal with other elements, it will be the last of such elements. If x is identical with another element, it will not be inserted. If insertion is successful the function returns 1, otherwise it returns 0.
	// Exception: _ORDEREDSET__SETFULL if set is full

	// special case: size_==0
	
    if (size_==0){
        elements_.append(newT);
        return 1;
    }

    for (int i=0; i < elements_.len();i++){
    	if (elements_[i]->id()==newT->id())
    		remove(elements_[i]->id());
    }
    
    // figure out index
    int idxToInsert=0; // insert at front if newEvent is smallest
    
    if (elements_.len()==1){
		if (*elements_[0]<=*newT){
			idxToInsert = 1;
    	}
    } else { // size_ > 1
		for (int i=elements_.len()-1;i>0;i--){
			if (elements_[i]<=newT){ // insert in the middle if newEvent is not smallest
				idxToInsert = i+1;
				break;
			}
		}
	}
	
    // perform insertion
    elements_.append() = newT;
    for (int i = elements_.len()-2; i >= idxToInsert; i--){
    	swap(elements_[i],elements_[i+1]);
    }  		 
    
    return 1;
}

template <typename T>
TPointer OrderedSet::removeFirst(){
	// pre: set should not be full
	// post: the first element in the set is removed and returned 
	// Exception: throw _ORDEREDSET__EMPTYSET
	if (elements_.len()==0) throw _ORDEREDSET__EMPTYSET;
	return elements_.pop(0);
}

template <typename T>
int OrderedSet::remove(int x){
	// post: remove the event with id x and return 1, or return 0 if its not found
	for (int i=0;i<size_;i++){
		if ( elements_[i]->id()==x ){
			elements_.pop(i);
			return 1;
		}
	}
	return 0;
}

template <typename T>
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

template <typename T>
int OrderedSet::len(){return elements_.len();}


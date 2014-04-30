using namespace std;

template <typename PointerType>
int OrderedSet<PointerType>::insert(PointerType newPointer){
	// pre: x is of comparable type with the rest of the set
	// post: x is inserted while maintaining order of the set. If x compares equal with other elements, it will be the last of such elements. If x is identical with another element, it will not be inserted. If insertion is successful the function returns 1, otherwise it returns 0.
	// Exception: SetFull if set is full

<<<<<<< HEAD
	// special case: L.length()==0
    if (L.length()==0){
        L.append(newPointer);
        return 1;
    }
    // stop insertion if set is full
    if (L.length()==maxsize_) return 0;
    // remove replica
    for (int i=0;i<L.length();i++){
    	if (L[i].id()==newPointer->id())
    		L.pop(i);
=======
	// special case: size_==0
	
    if (size_==0){
        elements_.append(newT);
        return 1;
    }

    for (int i=0; i < elements_.len();i++){
    	if (elements_[i]->id()==newT->id())
    		remove(elements_[i]->id());
>>>>>>> 55c0771c12720e70f73f2077c19b6f0e14baedc9
    }
    
    // figure out index to insert
    int idxToInsert=0; // insert at front if newEvent is smallest
    
<<<<<<< HEAD
    if (L.length()==1){
		if (L[0]<=*newPointer){
			idxToInsert = 1;
    	}
    } else { // L.length() > 1
		for (int i=L.length()-1;i>0;i--){
			if (L[i]<=*newPointer){ // insert in the middle if newEvent is not smallest
=======
    if (elements_.len()==1){
		if (*elements_[0]<=*newT){
			idxToInsert = 1;
    	}
    } else { // size_ > 1
		for (int i=elements_.len()-1;i>0;i--){
			if (elements_[i]<=newT){ // insert in the middle if newEvent is not smallest
>>>>>>> 55c0771c12720e70f73f2077c19b6f0e14baedc9
				idxToInsert = i+1;
				break;
			}
		}
	}
	
    // perform insertion
<<<<<<< HEAD
    L.insert(idxToInsert,newPointer);
=======
    elements_.append() = newT;
    for (int i = elements_.len()-2; i >= idxToInsert; i--){
    	swap(elements_[i],elements_[i+1]);
    }  		 
>>>>>>> 55c0771c12720e70f73f2077c19b6f0e14baedc9
    
    return 1;
}

template <typename PointerType>
PointerType OrderedSet<PointerType>::removeFirst(){
	// pre: set should not be full
	// post: the first element in the set is removed and returned 
<<<<<<< HEAD
	// Exception: throw EmptySet()
	if (L.length()==0) throw EmptySet();
	return L.pop(0);
=======
	// Exception: throw _ORDEREDSET__EMPTYSET
	if (elements_.len()==0) throw _ORDEREDSET__EMPTYSET;
	return elements_.pop(0);
>>>>>>> 55c0771c12720e70f73f2077c19b6f0e14baedc9
}

template <typename PointerType>
int OrderedSet<PointerType>::remove(int x){
	// post: remove the event with id x and return 1, or return 0 if its not found
<<<<<<< HEAD
	for (int i=0;i<L.length();i++){
		if ( L[i].id()==x ){
			L.pop(i);
=======
	for (int i=0;i<size_;i++){
		if ( elements_[i]->id()==x ){
			elements_.pop(i);
>>>>>>> 55c0771c12720e70f73f2077c19b6f0e14baedc9
			return 1;
		}
	}
	return 0;
}

template <typename PointerType>
string OrderedSet<PointerType>::str(){
	// post: returns the string representation of OrderedSet
    stringstream os;
    os << L;
    return os.str();
}

<<<<<<< HEAD
template <typename PointerType>
int OrderedSet<PointerType>::len(){return L.length();}
=======
template <typename T>
int OrderedSet::len(){return elements_.len();}
>>>>>>> 55c0771c12720e70f73f2077c19b6f0e14baedc9


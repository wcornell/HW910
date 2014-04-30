using namespace std;

template <typename PointerType>
int OrderedSet<PointerType>::insert(PointerType newPointer){
	// pre: x is of comparable type with the rest of the set
	// post: x is inserted while maintaining order of the set. If x compares equal with other elements, it will be the last of such elements. If x is identical with another element, it will not be inserted. If insertion is successful the function returns 1, otherwise it returns 0.
	// Exception: SetFull if set is full

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
    }
    
    // figure out index to insert
    int idxToInsert=0; // insert at front if newEvent is smallest
    
    if (L.length()==1){
		if (L[0]<=*newPointer){
			idxToInsert = 1;
    	}
    } else { // L.length() > 1
		for (int i=L.length()-1;i>0;i--){
			if (L[i]<=*newPointer){ // insert in the middle if newEvent is not smallest
				idxToInsert = i+1;
				break;
			}
		}
	}
	
    // perform insertion
    L.insert(idxToInsert,newPointer);
    
    return 1;
}

template <typename PointerType>
PointerType OrderedSet<PointerType>::removeFirst(){
	// pre: set should not be full
	// post: the first element in the set is removed and returned 
	// Exception: throw EmptySet()
	if (L.length()==0) throw EmptySet();
	return L.pop(0);
}

template <typename PointerType>
int OrderedSet<PointerType>::remove(int x){
	// post: remove the event with id x and return 1, or return 0 if its not found
	for (int i=0;i<L.length();i++){
		if ( L[i].id()==x ){
			L.pop(i);
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

template <typename PointerType>
int OrderedSet<PointerType>::len(){return L.length();}


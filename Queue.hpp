#include<string>
#include<sstream>
using namespace std;

template <typename T>
int Queue<T>::enqueue (T &x){
/*pre: The length of queue is <= maxsize
post: x is added to the end of the queue
returns an integer 0 if the enqueue fails and an integer 1 if it succeeds
*/			
	if(L.length() == maxsize_){ // if the array has reached its max size,
		return 0;			// return 0: enqueue has failed.
	} else if (L.length() < maxsize_){	
		L.insert(0,x);
		return 1;
	} else {
		throw IndexError();
	}
}

template <typename T>
T Queue<T>::dequeue(){
/*pre: the queue is not empty
post: removes and returns the next element in the queue
Exception: throws IndexError the Queue is full
*/
	if (L.length() == 0){ // throws 1 if the queue is empty
		throw IndexError();
	}
	T x;	
	x = L.pop();	// returns the top element of the queue
	return x;
}

template <typename T>
int Queue<T>::len(){
/*pre:
post: returns the integer value of the number of elements in the queue
*/
	return L.length();
	}

template <typename T>
std::string Queue<T>::str(){
/* creates a string representation of the queue*/
    stringstream os;
    os << L;
    return os.str();
}

	















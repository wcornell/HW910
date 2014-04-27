#include<string>
#include<sstream>
using namespace std;

template <typename T>
Queue::Queue(int maxsize){
//constructor
	people_ = new Customer[maxsize];
	maxsize_= maxsize;
	start_ = 0;
	tail_ = 0;
	length_=0;
}

template <typename T>
int Queue::enqueue (Customer &x){
/*pre: x is a Customer object
post: x is added to the end of the queue
returns an integer 0 if the enqueue fails and an integer 1 if it succeeds
*/			
	if(length_ == maxsize_){ 			// if the array has reached its max size,
		return 0;						// return 0: enqueue has failed.
	}
	if (length_ < maxsize_){			// if the array has not reached its max size,
		people_[tail_] = x;				// enqueue customer x
		tail_ = (tail_+1)%maxsize_;		// increment the length of the array
		length_++;
		return 1;						// and return 1 to show enqueue was successful
	}	
}

Customer Queue::dequeue(){
/*pre: the queue is not empty
post: removes and returns the next element in the queue
Exception: throws integer 1 if the Queue is full
*/
	if (length_ == 0){ // throws 1 if the queue is empty
		throw 1;
	}
	Customer finished;	
	finished = people_[start_];		// returns the top element of the queue 	
	start_ = (start_+1)%maxsize_;	// moves the head of the queue up one
	length_--;
	return finished;				
}
	
int Queue::len(){
/*pre:
post: returns the integer value of the number of elements in the queue
*/
	return length_;
	}
	
std::string Queue::str(){
/* creates a string representation of the queue*/
    stringstream os;
    if (length_==0){
    	os << "[]";
    	return os.str();
    }
    os << "[" << people_[start_].str() << "*";
    for(int i=start_;i<length_-1;i++){
    	os << ", " << people_[(i+1)%maxsize_].str();
    } 
    os << "]";
    return os.str();
}
Queue::~Queue(){
/*Destructor*/
	delete [] people_;
}    	

	















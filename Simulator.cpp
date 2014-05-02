#include "Simulator.h"
#include "Queue.h"
#include "Server.h"
#include "CustomerArrival.h"

using namespace std;

Simulator::Simulator(std::string arrivalFile, std::string serverFile, bool surpressOutput, int serverCount)
{
	S = new Server*[serverCount];
	vtime_ = 0; 
	arrivalFile_ = arrivalFile; 
	serverFile_ = serverFile;
	surpressOutput_=surpressOutput; 
	spaceAllocated_ = false;
	serverCount_ = serverCount;
}

Simulator::~Simulator(){
	if (spaceAllocated_){
		delete Q;
		for(int i = 0; i < serverCount_; i++){
			delete S[i];
		}
		delete A;
	}
	delete [] S;
}

void Simulator::setup(int custCount, double arrivalMean, int serverCount, double serviceMean)
{
	/* post: setup environment for checkout simulation
		1. construct a shared queue of custCount Customers
		2. construct a Server and a CustomerArrival object
		3. insert the CustomerArrival object into the OrderedSet
	*/
	if (spaceAllocated_){
		delete Q;
		for(int i = 0; i < serverCount_; i++){
			delete S[i];
		}
		delete A;
	}
	Q = new Queue<Customer>(custCount);
	for(int i = 0; i < serverCount_; i++){
		S[i] = new Server(serviceMean,Q,this,serverFile_);
		S[i]->setid(i);
	}
	A = new CustomerArrival(arrivalMean,Q,S,this, serverCount_, custCount,now(),arrivalFile_);
	insert(A);
	spaceAllocated_ = true;
}

int Simulator::insert(EPointer e){
	// post: inserts the given event into the OrderedSet
	// Exception: the set may be full _ORDEREDSET__SETFULL will be thrown
	events.insert(e);
	return 1;
}

void Simulator::doAllEvents(){
	// post: repeatedly removes the first event from the OrderedSet, updates virtual time to the time of the event and execute the event.
	while (events.len()>0){
		EPointer cur = events.removeFirst();
		vtime_ = cur->time();
		cur->execute();
	}
}

double Simulator::now() const {return vtime_;}



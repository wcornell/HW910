#include "Simulator.h"
#include "Queue.h"
#include "Server.h"
#include "CustomerArrival.h"

using namespace std;

Simulator::~Simulator(){
	delete Q;
	delete S;
	delete A;
}

void Simulator::setup(int custCount, double arrivalMean, double serviceMean){
	/* post: setup environment for checkout simulation
		1. construct a shared queue of custCount Customers
		2. construct a Server and a CustomerArrival object
		3. insert the CustomerArrival object into the OrderedSet
	*/
	Q = new Queue<Customer>(custCount);
	S = new Server(serviceMean,Q,this,serverFile_);
	A = new CustomerArrival(arrivalMean,Q,S,this,custCount,now(),arrivalFile_);
	insert(A);
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



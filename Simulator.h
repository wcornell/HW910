#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Event.h"
#include "Customer.h"
#include "Queue.h"
#include "OrderedSet.h"

class Server;
class CustomerArrival;

typedef Event* EPointer;

class Simulator{
public:
	Simulator(int serverCount = 1,std::string arrivalFile = "ArrivalReport.dat", bool surpressOutput = false);
	virtual ~Simulator();
	double now() const;
	int insert(EPointer e);
	void doAllEvents();
	int maxQueueLength(){return maxLenth_;};
	
	virtual void setup(int custCount, double arrivalMean = 10.0, double serviceMean = 5.0);
	
private:
	double vtime_;
	OrderedSet<EPointer> events;
	std::string arrivalFile_;
	bool surpressOutput_;
	Queue<Customer>* Q;
	Server** S;
	CustomerArrival* A;
	int serverCount_;
	bool spaceAllocated_;
	int maxLenth_;
};


#endif // SIMULATOR_H

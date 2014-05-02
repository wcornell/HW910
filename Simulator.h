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
	Simulator(std::string arrivalFile = "ArrivalReport.dat", std::string serverFile = "ServerReport.dat", bool surpressOutput = false)
		{vtime_=0; arrivalFile_ = arrivalFile; serverFile_ = serverFile;surpressOutput_=surpressOutput; spaceAllocated_ = false};
	virtual ~Simulator();
	double now() const;
	int insert(EPointer e);
	void doAllEvents();
	
	virtual void setup(int custCount, double arrivalMean = 10.0, int serverCount, double serviceMean = 5.0);
	
private:
	double vtime_;
	OrderedSet<EPointer> events;
	std::string arrivalFile_, serverFile_;
	bool surpressOutput_;
	Queue<Customer>* Q;
	Server* S;
	CustomerArrival* A;
	int servercount_;
	bool spaceAllocated_;
};


#endif // SIMULATOR_H

#ifndef SERVER_H
#define SERVER_H
#include <random>
#include <fstream>
#include "Event.h"
#include "Customer.h"
#include "Queue.h"
#include "Simulator.h"

#define _SERVER_ID 1
#define _SERVER_QUEUEFULL 2

class Server: public Event {
public:
	Server(double mean = 7.0, Queue<Customer>* queue = NULL, Simulator* sim = NULL, std::string statusFile = "ServerReport.dat");
	virtual ~Server();
	virtual std::string str() const;
	bool available();
	void startService(Customer &c);
	void execute();
	void reportStatus();
	void setid(int id = 0);
	
private:
	double mean_;
	Queue<Customer>* Q;
	Simulator* sim_;
	Customer current;
	bool busy;
	int count;
	double lastStart;
	double waitTime;
	double totalServiceTime;
	
	std::random_device seed;
	std::default_random_engine *gen;
	std::exponential_distribution<> *exp;
	
	FILE* status;

};

#endif // SERVER_H

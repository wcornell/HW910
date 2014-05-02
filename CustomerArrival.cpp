/* Louie Quicksell & Paul Young
CustomerArrival.h
CS 173 - Dr. Bressoud */

#include "CustomerArrival.h"

using namespace std;

CustomerArrival::CustomerArrival(double mean, Queue<Customer>* queue, Server** server, Simulator * sim, int serverCount, int count, double time, string statusFile)	// Constructor
{
	mean_ = mean;
	Q = queue;
	S=server;
	sim_ = sim;
	count_ = count;
	time_ = time;
	id_ = _CUSTOMERARRIVAL_ID;
	exp = new exponential_distribution<>(1/mean);
	gen = new default_random_engine(seed());
	serverCount_ = serverCount;
	num_=0;
	
	busyServer = 0;
	lastArrival = 0;
	
	status = fopen(statusFile.c_str(),"w");
	fprintf(status,"       now   Tservice   count     busy  Q.len()  meanWait\n");
}

CustomerArrival::~CustomerArrival(){
	delete exp;
	delete gen;
	fclose(status);
}

void CustomerArrival::execute(){

	reportStatus();
	
	lastArrival = sim_->now();
	
	// create the new Customer with appropriate time and label
	ostringstream convert;
	convert << ++num_;
	Customer cust(sim_->now(), convert.str());
	
	bool serviced = false;
	// decide what to do with the Customer
	for(int i = 0; i < serverCount_; i++){
		if (S[i]->available()){
			S[i]->startService(cust);
			serviced = true;
			break;
		}
	}
	if (!serviced){
		busyServer += 1;
		Q->enqueue(cust);
	}
	
	// schedule next CustomerArrival if allowed
	if (num_ < count_){
		time_ = sim_->now() + (*exp)(*gen);
		sim_->insert(this);
	}
	
	return;
}

void CustomerArrival::reportStatus(){
	fprintf(status,"%10.2f %10.2f %5d %10.2f %5d\n"
		,sim_->now(), sim_->now()-lastArrival, num_, busyServer/(double)num_, Q->len());
}

string CustomerArrival::str() const{
	// post: returns the string representation of the CustomerArrival class
	ostringstream os;
	os << "<Arrival " << id_ << ":" << time_ << ">";
	return os.str();
}

	

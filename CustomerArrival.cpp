/* Louie Quicksell & Paul Young
CustomerArrival.h
CS 173 - Dr. Bressoud */

#include "CustomerArrival.h"

using namespace std;

CustomerArrival::CustomerArrival(double mean, Queue<Customer>* queue, Server** server, Simulator * sim, int serverCount, int count, double time, string statusFile)	// Constructor
{
	mean_ = mean;
	Q = queue;
	for(int i = 0; i < serverCount_; i++){
		S[i] = server[i];
	}
	sim_ = sim;
	count_ = count;
	time_ = time;
	id_ = _CUSTOMERARRIVAL_ID;
	exp = new exponential_distribution<>(1/mean);
	gen = new default_random_engine(seed());
	serverCount_ = serverCount;
	
	busyServer = 0;
	lastArrival = 0;
	
	status.open(statusFile.c_str(),ios::out);
	status << "now interval count  %busy  Q.len()" << endl;
}

CustomerArrival::~CustomerArrival(){
	delete exp;
	delete gen;
	status.close();
}

void CustomerArrival::execute(){

	reportStatus();
	
	lastArrival = sim_->now();
	
	// create the new Customer with appropriate time and label
	ostringstream convert;
	convert << ++num_;
	Customer cust(sim_->now(), convert.str());
	
	// decide what to do with the Customer
	for(int i = 0; i < serverCount_; i++){
		if (S[i]->available()){
			S[i]->startService(cust);
		}else{
			busyServer += 1;
			Q->enqueue(cust);
		}
	}
	// schedule next CustomerArrival if allowed
	if (num_ < count_){
		time_ = sim_->now() + (*exp)(*gen);
		sim_->insert(this);
	}
	
	return;
}

void CustomerArrival::reportStatus(){
	status << sim_->now() << " " << sim_->now()-lastArrival << " " << num_ << " " << busyServer/(double)num_ << " " << Q->len() << " " << endl;
}

string CustomerArrival::str() const{
	// post: returns the string representation of the CustomerArrival class
	ostringstream os;
	os << "<Arrival " << id_ << ":" << time_ << ">";
	return os.str();
}

	

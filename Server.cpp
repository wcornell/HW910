#include <sstream>
#include <stdio.h>
#include "Server.h"

using namespace std;
Server::Server(double mean, Queue<Customer>* queue, Simulator* sim, string statusFile){
	mean_=mean;
	Q=queue; 
	sim_=sim; 
	busy=false; 
	count=0; 
	lastStart = 0;
	waitTime = 0; 
	totalServiceTime = 0; 
	time_=0; 
	exp = new exponential_distribution<>(1/mean);
	gen = new default_random_engine(seed());
	
	status = fopen(statusFile.c_str(),"w");
	fprintf(status, "       now   Tservice   count     busy  Q.len()  meanWait\n");
	/*status.open(statusFile.c_str(),ios::out);
	status << "now  Tservice count  %busy  Q.len() meanWait" << endl;*/
}

Server::~Server(){
	delete exp;
	delete gen;
	fclose(status);
}

void Server::startService(Customer& c){
	// pre: Q is not full and sim_->events is not full
	// post: start serving Customer c if available, otherwise puts c in Queue
	// Exception: _SERVER_QUEUEFULL if Q is full, _SERVER_EVENTSFULL if events is full
	if (!available()){
		if (!Q->enqueue(c)) throw _SERVER_QUEUEFULL;
	} else {
		// record stats
		waitTime += sim_->now() + c.time();
		lastStart = sim_->now();
		current = c;
		
		// reschedule
		busy = true;
		time_ = sim_->now() + (*exp)(*gen);
		sim_->insert(this);
	}
}

void Server::execute(){

	reportStatus();
	// record stats
	count++;
	totalServiceTime += sim_->now()-lastStart;
	busy = false;
	
	// grab a customer from the queue if there is one
	if (Q->len()!=0){
		current = Q->dequeue();
		startService(current);
	}
	
	return;
	
}

void Server::reportStatus(){
	/*status << sim_->now() << " " << sim_->now()-lastStart << " " << count << " " << totalServiceTime/sim_->now() << " " << Q->len() << " " << waitTime/(double)count << endl;*/
	
	fprintf(status,"%10.2f %10.2f %5d %10.2f %5d %10.2f\n"
		,sim_->now(), sim_->now()-lastStart, count, totalServiceTime/sim_->now(), Q->len(), waitTime/(double)count);
}

bool Server::available(){return !busy;}
string Server::str() const{
	// post: returns the string representation of the Server class
	ostringstream os;
	os << "<Server " << id_ << ":" << time_ << ">";
	return os.str();
}

void Server::setid(int id){id_ = id;}

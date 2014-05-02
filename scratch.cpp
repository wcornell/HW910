#include <iostream>
#include "Simulator.h"

#define NUM_CUSTOMER 1000

using namespace std;

int main(int argc, char* argv[]){

	if (argc != 4){
	cout << "usage: ./scratch arrivalMean serviceMean numberOfServers" << endl;
	return -1;
	}
	
	double arrivalMean;
	double serviceMean;
	int numberOfServers;
	arrivalMean = atof(argv[1]);
	serviceMean = atof(argv[2]);
	numberOfServers = atoi(argv[3]);
	
	Simulator S(numberOfServers);
	S.setup(NUM_CUSTOMER,arrivalMean,serviceMean);
	S.doAllEvents();

  
return 0;
}

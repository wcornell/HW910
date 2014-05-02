#include <iostream>
#include "Simulator.h"

#define N_CUSTOMER 1000
#define N_RUN 100

using namespace std;

int main(int argc, char* argv[]){

	if (argc != 4){
	cout << "usage: ./queue arrivalMean serviceMean numberOfServers" << endl;
	return -1;
	}
	
	double arrivalMean;
	double serviceMean;
	int numberOfServers;
	arrivalMean = atof(argv[1]);
	serviceMean = atof(argv[2]);
	numberOfServers = atoi(argv[3]);
	
	FILE* fmaxQueue;
	double avg = 0;
	fmaxQueue = fopen("maxQueue.dat","w");
	
	for (int i=0;i<N_RUN;i++){
		Simulator S(numberOfServers);
		S.setup(N_CUSTOMER,arrivalMean,serviceMean);
		S.doAllEvents();
		avg+=S.maxQueueLength();
		fprintf(fmaxQueue,"%d\n",S.maxQueueLength());
	}
	
	fclose(fmaxQueue);
	cout << avg/(double)N_RUN << endl;

return 0;
}

#include <iostream>
#include <sys/stat.h>
#include "Simulation.h"

using namespace std;

int main(){

	double arrivalMean = 1.0;
	double serviceMean = 5.0;
	mkdir("Data",0777);
	Simulator single("Data/Arrival.dat","Data/Server.dat");
	single.setup(1000,arrivalMean,serviceMean);
	single.doAllEvents();

   
return 0;
}

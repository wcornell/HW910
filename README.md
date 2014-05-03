CS173
======

 Final Homework Project 9-10
 William Cornell
 Paul Young
 
Usage
------
We focused on the behavior of maxQueueLength.

Makefile will generate 4 tests and an executable called "queue"
queue is compiled from the driver "scratch.cpp" which takes 3 parameters arrivalMean, serviceMean and numberOfServers and runs the simulation for 1000 customers 100 times. It outpus the average maxiimum queue length at the end of the simulation.

To explore the dependence of maxiimum queue length on service power(numberOfServers * 1/serviceMean) I issued the command:
rm queue.dat; for i in {1..10}; do ./queue 10 $(($i * 5)) $i >> queue.dat; done

To determine the transition point for queue stability, I issued the command:
rm queue.dat; for i in {5..20} do queue.dat; queue 10 $i 1 

Results
------
 1. Even when the service power is constant, the maximum Queue Length decreases linearly as the numberOfServers increases.
 2. For arrivalMean=10, maxLenth undergoes a stable->unstable transition when the above ratio is around 5.
 
Description
------
 Our final project is a generalization of the
 M/M/1 queueing simulation that we did for HW8.
 We have generalized the model in two important
 ways. The first is by templatizing the simulator
 such that it can be more easily converted to
 run different simulations. The second way in
 which we generalized the model is by making the
 simulator work for any given number of servers,
 passed upon creation of the simulator.
 
 Rather than maintaining a pointer to a single
 server, the simulator and customer arrival
 objects now maintain pointers to an array of
 pointers to servers. Each server uses the same
 shared queue of customers, however, as this
 model is still effective for the grocery store
 problem. Any time a particular server's queue
 is empty and a new customer arrives, they would
 choose to go to an immediately available server
 rather than wait in line.
 
 Generalizing the simulation for any number of 
 servers has some key advantages. The first may
 seem rather obvious in that real world applications
 (real grocery stores) have multiple cashiers all
 working at once. This also allows us, if we have
 some experimental information about the
 distributions of customer arrivals and service
 times, allows us to look at what the optimal
 number of servers is such that the length of the
 queue never grows without bound. We can determine
 how "stable" a particular scenario is in this
 regard by observing the overall slope of the graph
 of the length of the queue. If it is positive over
 a long period, then more servers are needed.

________/\\\\\\\\\_____/\\\\\\\\\\\________/\\\__/\\\\\\\\\\\\\\\_____/\\\\\\\\\\__        
 _____/\\\////////____/\\\/////////\\\__/\\\\\\\_\/////////////\\\___/\\\///////\\\_       
  ___/\\\/____________\//\\\______\///__\/////\\\____________/\\\/___\///______/\\\__      
   __/\\\_______________\////\\\_____________\/\\\__________/\\\/____________/\\\//___     
    _\/\\\__________________\////\\\__________\/\\\________/\\\/_____________\////\\\__    
     _\//\\\____________________\////\\\_______\/\\\______/\\\/__________________\//\\\_   
      __\///\\\___________/\\\______\//\\\______\/\\\____/\\\/___________/\\\______/\\\__  
       ____\////\\\\\\\\\_\///\\\\\\\\\\\/_______\/\\\__/\\\/____________\///\\\\\\\\\/___ 
        _______\/////////____\///////////_________\///__\///________________\/////////_____

 
 Final Homework Project 9-10
 William Cornell
 Paul Yang
 
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

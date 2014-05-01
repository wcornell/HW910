all: scratch
	
scratch: scratch.cpp Event.cpp Customer.cpp CustomerArrival.cpp Server.cpp Simulator.cpp
	g++ -o $@ -g -std=c++0x $^
	

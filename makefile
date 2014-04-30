all: scratch
	
scratch: scratch.cpp Customer.cpp
	g++ -o $@ -g $^
	

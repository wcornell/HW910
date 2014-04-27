all: scratch
	
scratch: scratch.cpp
	g++ -o $@ -g $^
	

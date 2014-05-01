all: scratch
	
scratch: scratch.cpp Event.cpp
	g++ -o $@ -g $^
	

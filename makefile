all: scratch

DLListInt.o : DLListInt.h DLListInt.cpp
	g++ -c DLListInt.cpp -o $@
	
scratch: DLListInt.o scratch.cpp
	g++ -o $@ $^
	

/*
Customer.cpp
Author: Bryan Fowler
Date:4/1/14
CS173
*/
#include "Customer.h"
#include <iostream>
#include <sstream>

using namespace std;

string Customer::str() const{
//Creates a string representation of a Customer object
	stringstream s;
	s << "<Customer "<<label_<<": "<<time_<<">";
	return s.str();	
}
	
double Customer::time() const{return time_;}
//returns the time value of a Customer object

string Customer::label() const{return label_;}
//returns the string label f a Customer object

void Customer::setTime(double time){time_=time;}
//pre: time is a double
//post: changes the Customer time value to time

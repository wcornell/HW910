#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>

class Customer;
std::ostream& operator<<(std::ostream& os, const Customer& c);

class Customer{
	public:
		Customer(double time=0.0, std::string label=""){time_ = time;label_ = label;};
		std::string str() const;
		double time() const;
		std::string label() const;
		void setTime(double time);
		
	private:
		double time_;
		std::string label_;
		
	// Non-member friends
	friend std::ostream& operator<<(std::ostream& os, const Customer& c);
};

#endif

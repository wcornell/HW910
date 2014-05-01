/*  Queue.h
Author: Bryan Fowler
Date: 3/31/14
CS 173  */

#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<sstream>
#include "DLList.h"

#define _QUEUE_INDEXERROR 0
#define _QUEUE_MAXSIZE 1000

template <typename T>
class Queue{
	public:
		Queue(int maxsize = _QUEUE_MAXSIZE){maxsize_=maxsize;};
		~Queue(){};
		int enqueue(T &x);
		T dequeue();
		int len();
		std::string str();
	
	private:
		int maxsize_;
		DLList<T> L;
};

#include "Queue.hpp"
#endif	
			

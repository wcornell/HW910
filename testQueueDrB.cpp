#include <gtest/gtest.h>
#include "Queue.h"
#include "Customer.h"
#include <iostream>

using namespace std;

TEST(Queue, EmptyConstructor) {
// create empty queue
	Queue<Customer> q;
	EXPECT_EQ(string("[]"), q.str());
	
	Queue<Customer> q2(128);
  EXPECT_EQ(string("[]"), q2.str());
}


TEST(Queue, EmptyConstructorLen) {
// create empty queue
  Queue<Customer> q;
  EXPECT_EQ(0, q.len());
  
  Queue<Customer> q2(128);
  EXPECT_EQ(0, q2.len());
}

TEST(Queue, Enqueue1) {
  Queue<Customer> q;
  Customer c1(3, "Fred");
  int n;
  
  n = q.enqueue(c1);
  string exp("[<Customer Fred: 3");
  EXPECT_EQ(exp, q.str().substr(0, exp.length()));
  EXPECT_EQ(string(">*]"), q.str().substr(q.str().length()-3, 3));
  EXPECT_TRUE(n);
  EXPECT_EQ(1, q.len());
}

TEST(Queue, Enqueue1Dequeue1) {
  Queue<Customer> q;
  Customer c1(3, "Fred");
  Customer c2;
  int n;
  
  n = q.enqueue(c1);
  c2 = q.dequeue();
  EXPECT_TRUE(n);
  EXPECT_EQ(0, q.len());
  EXPECT_EQ(string("[]"), q.str());
  EXPECT_EQ(3, c2.time());
  EXPECT_EQ(string("Fred"), c2.label());
}

TEST(Queue, Enqueue2Dequeue2) {
  Queue<Customer> q;
  Customer c1(3, string("Fred"));
  Customer c2(4, string("George"));
  int n1, n2;
  Customer c3, c4;
  
  n1 = q.enqueue(c1);
  n2 = q.enqueue(c2);
  c3 = q.dequeue();
  c4 = q.dequeue();
  EXPECT_TRUE(n1);
  EXPECT_TRUE(n2);
  EXPECT_EQ(0, q.len());
  EXPECT_EQ(string("[]"), q.str());
  EXPECT_EQ(3, c3.time());
  EXPECT_EQ(string("Fred"), c3.label());
  EXPECT_EQ(4, c4.time());
  EXPECT_EQ(string("George"), c4.label());
}

TEST(Queue, Enqueue3Dequeue3Mix) {
  Queue<Customer> q;
  Customer c1(3, string("Fred"));
  Customer c2(4, string("George"));
  Customer c3(5, string("Harry"));
  int n1, n2, n3;
  Customer c4, c5, c6;
  
  n1 = q.enqueue(c1);
  n2 = q.enqueue(c2);
  c4 = q.dequeue();
  n3 = q.enqueue(c3);
  EXPECT_EQ(2, q.len());
  c5 = q.dequeue();
  c6 = q.dequeue();
  
  EXPECT_TRUE(n1);
  EXPECT_TRUE(n2);
  EXPECT_TRUE(n3);
  EXPECT_EQ(0, q.len());
  EXPECT_EQ(string("[]"), q.str());
  EXPECT_EQ(3, c4.time());
  EXPECT_EQ(string("Fred"), c4.label());
  EXPECT_EQ(4, c5.time());
  EXPECT_EQ(string("George"), c5.label());
  EXPECT_EQ(5, c6.time());
  EXPECT_EQ(string("Harry"), c6.label());
}

TEST(Queue, EnqueueFull) {
	Queue<Customer> q(3);
	Customer c1(4);
	Customer c2(5);
	Customer c3(6);
	Customer c4(7);
  Customer c5(8);

  Customer c6;
	Customer c7;

	int n = q.enqueue(c1);
	EXPECT_TRUE(n);
	n = q.enqueue(c2);
  EXPECT_TRUE(n);
  n = q.enqueue(c3);
  EXPECT_TRUE(n);

  q.dequeue();
  n = q.enqueue(c4);
  EXPECT_TRUE(n);
  n = q.enqueue(c5);
  EXPECT_FALSE(n);
}
	
TEST(Queue, DequeueEmpty) {
	Queue<Customer> q;
	EXPECT_THROW(q.dequeue(), int);
}

TEST(Queue, DequeueEmptyInOut) {
  Queue<Customer> q;
  Customer c1(3);
  Customer c2;
  q.enqueue(c1);
  c2 = q.dequeue();
  EXPECT_THROW(q.dequeue(), int);
}

TEST(Queue, len) {
	Queue<Customer> q;
	Customer x(6);
	Customer y(8);
	Customer z(10);
	
	EXPECT_EQ(q.len(), 0);
	q.enqueue(x);
	EXPECT_EQ(q.len(), 1);
	q.enqueue(y);
	EXPECT_EQ(q.len(), 2);
	q.enqueue(z);
	EXPECT_EQ(q.len(), 3);
	q.dequeue();
	EXPECT_EQ(q.len(), 2);
}

TEST(Queue, WrapAround1)
{
  Queue<Customer> q(4);
  int n;
  
  Customer c1(1);
  Customer c2(2);
  Customer c3(3);
  Customer c4(4);
  Customer c5(5);
  Customer c6(6);

  Customer c7, c8, c9, c10, c11, c12;
    
  n = q.enqueue(c1);
  EXPECT_TRUE(n);
  n = q.enqueue(c2);
  EXPECT_TRUE(n);
  n = q.enqueue(c3);
  EXPECT_TRUE(n);
  c7 = q.dequeue();
  n = q.enqueue(c4);
  EXPECT_TRUE(n);
  n = q.enqueue(c5);
  EXPECT_TRUE(n);
  c8 = q.dequeue();
  n = q.enqueue(c6);
  EXPECT_TRUE(n);
  c9 = q.dequeue();
  c10 = q.dequeue();
  c11 = q.dequeue();
  c12 = q.dequeue();
  EXPECT_EQ(1, c7.time());
  EXPECT_EQ(2, c8.time());
  EXPECT_EQ(3, c9.time());
  EXPECT_EQ(4, c10.time());
  EXPECT_EQ(5, c11.time());
  EXPECT_EQ(6, c12.time());
}

TEST(Queue, WrapAround2)
{
  Queue<Customer> q(4);
  int n;

  Customer c1(1);
  Customer c2(2);
  Customer c3(3);
  Customer c4(4);
  Customer c5(5);
  Customer c6(6);

  Customer c7, c8, c9, c10, c11, c12;

  n = q.enqueue(c1);
  EXPECT_TRUE(n);
  n = q.enqueue(c2);
  EXPECT_TRUE(n);
  n = q.enqueue(c3);
  EXPECT_TRUE(n);
  n = q.enqueue(c4);
  EXPECT_TRUE(n);
  c7 = q.dequeue();
  n = q.enqueue(c5);
  EXPECT_TRUE(n);
  c8 = q.dequeue();
  n = q.enqueue(c6);
  EXPECT_TRUE(n);
  c9 = q.dequeue();
  c10 = q.dequeue();
  c11 = q.dequeue();
  c12 = q.dequeue();
  EXPECT_EQ(1, c7.time());
  EXPECT_EQ(2, c8.time());
  EXPECT_EQ(3, c9.time());
  EXPECT_EQ(4, c10.time());
  EXPECT_EQ(5, c11.time());
  EXPECT_EQ(6, c12.time());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


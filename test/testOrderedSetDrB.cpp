/*
 * testOrderedSetDrB.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: tashi
 */

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "../OrderedSet.h"
#include "../Server.h"

using namespace std;

TEST(OrderedSet, EmptyConstructor)
{
  OrderedSet<Event*> S;
  EXPECT_EQ(S.str(), string("[]"));
  EXPECT_EQ(S.len(), 0);
}

TEST(OrderedSet, InsertOne)
{
  OrderedSet<Event*> S;
  Event e1;
  S.insert(&e1);
  string expect("[<Event 0: -1");
  EXPECT_EQ(expect, S.str().substr(0, expect.length()));
  EXPECT_EQ(string(">*]"), S.str().substr(S.str().length() - 3, 3));
}

TEST(OrderedSet, InsertOneTestLen)
{
  OrderedSet<Event*> S;
  Event e1;
  S.insert(&e1);
  string expect("[<Event 0: -1");
  EXPECT_EQ(1, S.len());
}

TEST(OrderedSet, InsertTwoSameEvent)
{
  OrderedSet<Event*> S;
  Event e(2, 2.5);
  S.insert(&e);
  S.insert(&e);
  EXPECT_EQ(1, S.len());
  string expect("[<Event 2: 2.5");
  EXPECT_EQ(expect, S.str().substr(0, expect.length()));
  EXPECT_EQ(string(">*]"), S.str().substr(S.str().length() - 3, 3));
}

TEST(OrderedSet, InsertRemoveOne)
{
  OrderedSet<Event*> S;
  Event e1(2, 2.5);
  S.insert(&e1);
  Event * e2;
  e2 = S.removeFirst();
  EXPECT_EQ(2, e2->id());
  EXPECT_EQ(2.5, e2->time());
  EXPECT_EQ(0, S.len());
}

TEST(OrderedSet, RemoveFirstEmpty)
{
  OrderedSet<Event*> S;
  EXPECT_THROW(S.removeFirst(), int);
}

TEST(OrderedSet, RemoveFirstEmptyInOut)
{
  OrderedSet<Event*> S;
  Event e;
  S.insert(&e);
  S.removeFirst();
  EXPECT_THROW(S.removeFirst(), int);
}

TEST(OrderedSet, InsertTwoDiffValInorder)
{
  OrderedSet<Event*> S;
  Event e1(2, 2.5);
  Event e2(1, 3.5);
  S.insert(&e1);
  S.insert(&e2);
  EXPECT_EQ(2, S.len());
  Event * e3;
  e3 = S.removeFirst();
  EXPECT_EQ(2, e3->id());
  EXPECT_EQ(2.5, e3->time());
}

TEST(OrderedSet, InsertTwoDiffValOutorder)
{
  OrderedSet<Event*> S;
  Event e1(2, 3.5);
  Event e2(1, 2.5);
  S.insert(&e1);
  S.insert(&e2);
  EXPECT_EQ(2, S.len());
  Event * e3;
  e3 = S.removeFirst();
  EXPECT_EQ(1, e3->id());
  EXPECT_EQ(2.5, e3->time());
}

TEST(OrderedSet, InsertTwoSameVal)
{
  OrderedSet<Event*> S;
  Event e1(2, 3.5);
  Event e2(1, 3.5);
  S.insert(&e1);
  S.insert(&e2);
  EXPECT_EQ(2, S.len());
  Event * e3;
  e3 = S.removeFirst();
  EXPECT_EQ(2, e3->id());
  EXPECT_EQ(3.5, e3->time());
}

TEST(OrderedSet, InsertMultipleDistinct)
{
  OrderedSet<Event*> S;
  Event e1(1, 5);
  Event e2(2, 2.5);
  Event e3(3, 4.25);
  S.insert(&e1);
  S.insert(&e2);
  S.insert(&e3);
  EXPECT_EQ(3, S.len());
  Event *e4, *e5;
  e4 = S.removeFirst();
  e5 = S.removeFirst();
  EXPECT_EQ(2, e4->id());
  EXPECT_EQ(2.5, e4->time());
  EXPECT_EQ(3, e5->id());
  EXPECT_EQ(4.25, e5->time());
}

TEST(OrderedSet, InsertMultipleWRepeat)
{
  OrderedSet<Event*> S;
  Event e1(1, 5);
  Event e2(2, 9.5);
  Event e3(3, 5);
  Event e4(4, 5);
  S.insert(&e1);
  S.insert(&e2);
  S.insert(&e3);
  S.insert(&e4);
  EXPECT_EQ(4, S.len());

  //cout << S.str() << endl;

  Event *e5, *e6, *e7;
  e5 = S.removeFirst();
  e6 = S.removeFirst();
  e7 = S.removeFirst();
  EXPECT_EQ(1, e5->id());
  EXPECT_EQ(5, e5->time());
  EXPECT_EQ(3, e6->id());
  EXPECT_EQ(5, e6->time());
  EXPECT_EQ(4, e7->id());
  EXPECT_EQ(5, e7->time());
}

TEST(OrderedSet, InsertDupDown1)
{
  OrderedSet<Event*> S;
  Event e1(1, 5);
  Event e2(2, 9.5);
  Event e3(3, 7);
  Event e4(4, 2);
  S.insert(&e1);
  S.insert(&e2);
  S.insert(&e3);
  S.insert(&e4);
  Event e5(3, 2.5);
  S.insert(&e5);
  S.removeFirst();
  Event *e6;
  e6 = S.removeFirst();
  EXPECT_EQ(3, e6->id());
  EXPECT_EQ(2.5, e6->time());
}

TEST(OrderedSet, InsertDupDown2)
{
  OrderedSet<Event*> S;
  Event e1(1, 5);
  Event e2(2, 9.5);
  Event e3(3, 7);
  Event e4(4, 2);
  S.insert(&e1);
  S.insert(&e2);
  S.insert(&e3);
  S.insert(&e4);
  Event e5(3, 1.5);
  S.insert(&e5);
  Event *e6;
  e6 = S.removeFirst();
  EXPECT_EQ(3, e6->id());
  EXPECT_EQ(1.5, e6->time());
}

TEST(OrderedSet, InsertDupUp1)
{
  OrderedSet<Event*> S;
  Event e1(1, 5);
  Event e2(2, 9.5);
  Event e3(3, 7);
  Event e4(4, 2);
  S.insert(&e1);
  S.insert(&e2);
  S.insert(&e3);
  S.insert(&e4);
  Event e5(4, 9.5);
  S.insert(&e5);
  S.removeFirst();
  S.removeFirst();
  S.removeFirst();
  Event *e6;
  e6 = S.removeFirst();
  EXPECT_EQ(4, e6->id());
  EXPECT_EQ(9.5, e6->time());
}

TEST(OrderedSet, InsertDupUp2)
{
  OrderedSet<Event*> S;
  Event e1(1, 5);
  Event e2(2, 9.5);
  Event e3(3, 7);
  Event e4(4, 2);
  Event e5(5, 7);
  S.insert(&e1);
  S.insert(&e2);
  S.insert(&e3);
  S.insert(&e4);
  S.insert(&e5);
  Event e6(1, 7);
  S.insert(&e6);
  S.removeFirst();
  S.removeFirst();
  S.removeFirst();
  Event *e7;
  e7 = S.removeFirst();
  EXPECT_EQ(1, e7->id());
  EXPECT_EQ(7, e7->time());
}

TEST(OrderedSet, Remove)
{
  OrderedSet<Event*> S;
  Event e1(1, 5);
  Event e2(2, 3);
  S.insert(&e1);
  S.insert(&e2);
  S.remove(2);
  Event *e3;
  e3 = S.removeFirst();
  EXPECT_EQ(1, e3->id());

  S.insert(&e1);
  S.insert(&e2);
  S.remove(1);
  e3 = S.removeFirst();
  EXPECT_EQ(2, e3->id());
}

TEST(OrderedSet, BadRemove)
{
  OrderedSet<Event*> S;
  Event e1(1, 5);
  Event e2(2, 3);
  S.insert(&e1);
  S.insert(&e2);
  int val = S.remove(3);
  EXPECT_FALSE(val);
}

TEST(OrderedSet, InsertOnFull)
{
  OrderedSet<Event*> S(4);
  Event e1(1, 5);
  Event e2(2, 9.5);
  Event e3(3, 7);
  Event e4(4, 2);
  S.insert(&e1);
  S.insert(&e2);
  S.insert(&e3);
  int val = S.insert(&e4);
  EXPECT_TRUE(val);

  Event e5(5, 2);
  val = S.insert(&e5);
  EXPECT_FALSE(val);
}

TEST(OrderedSet, InsertDupOnFull)
{
  OrderedSet<Event*> S(4);
  Event e1(1, 5);
  Event e2(2, 9.5);
  Event e3(3, 7);
  Event e4(4, 2);
  S.insert(&e1);
  S.insert(&e2);
  S.insert(&e3);
  S.insert(&e4);
  Event e5(1, 2);
  int val = S.insert(&e5);
  EXPECT_TRUE(val);
  S.removeFirst();
  Event *e6;
  e6 = S.removeFirst();
  EXPECT_EQ(1, e6->id());
  EXPECT_EQ(2, e6->time());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

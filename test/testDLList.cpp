#include <gtest/gtest.h>
#include "../DLList.h"
#include <iostream>
#include <sstream>

using namespace std;

TEST(DLList, EmptyConstructor) {
// create empty queue and verify string representation
	DLList L;
	EXPECT_EQ(0, L.length());
	EXPECT_EQ(string("[]"), L.str());
}

TEST(DLList, AppendOne) {
  DLList L;
  L.append(5);
  EXPECT_EQ(string("[5]"), L.str());

  DLList T;
  T.append(-10);
  EXPECT_EQ(string("[-10]"), T.str());
}

TEST(DLList, InsertOne) {
  DLList L;
  L.insert(0, 5);
  EXPECT_EQ(string("[5]"), L.str());

  DLList T;
  T.insert(0, -10);
  EXPECT_EQ(string("[-10]"), T.str());
}

TEST(DLList, AppendTwo) {
  DLList L;
  L.append(5);
  L.append(-10);
  EXPECT_EQ(string("[5, -10]"), L.str());
}

TEST(DLList, InsertTwoAtHead) {
  DLList L;
  L.insert(0, 5);
  L.insert(0, -10);
  EXPECT_EQ(string("[-10, 5]"), L.str());
}

TEST(DLList, InsertTwoInOrder) {
  DLList L;
  L.insert(0, 5);
  L.insert(1, -10);
  EXPECT_EQ(string("[5, -10]"), L.str());
}

TEST(DLList, AppendThree) {
  DLList L;
  L.append(5);
  L.append(-10);
  L.append(7);
  EXPECT_EQ(string("[5, -10, 7]"), L.str());
}

TEST(DLList, InsertThreeAtHead) {
  DLList L;
  L.insert(0, 5);
  L.insert(0, -10);
  L.insert(0, 7);
  EXPECT_EQ(string("[7, -10, 5]"), L.str());
}

TEST(DLList, AppendThreeInsertMiddle) {
  DLList L;
  L.append(5);
  L.append(-10);
  L.append(7);
  L.insert(2, 1);
  EXPECT_EQ(string("[5, -10, 1, 7]"), L.str());

  DLList T;
  T.append(5);
  T.append(-10);
  T.append(7);
  T.insert(1, 1);
  EXPECT_EQ(string("[5, 1, -10, 7]"), T.str());
}

TEST(DLList, AccessAscending)
{
  DLList L;
  for (int i = 0; i < 5; i++) {
    L.insert(i, i);
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(i, L[i]);
  }
}

TEST(DLList, AccessDescending)
{
  DLList L;
  for (int i = 0; i < 5; i++) {
    L.insert(i, 5-i);
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(5-i, L[i]);
  }
}

TEST(DLList, PopOnly)
{
  int val;
  DLList L;
  L.append(5);
  val = L.pop();
  EXPECT_EQ(5, val);
  EXPECT_EQ(string("[]"), L.str());
  EXPECT_EQ(0, L.length());
}

TEST(DLList, PopLast)
{
  DLList L;
  int val1, val2, val3;
  L.append(5);
  L.append(7);
  L.append(3);

  val1 = L.pop();
  val2 = L.pop();
  val3 = L.pop();

  EXPECT_EQ(3, val1);
  EXPECT_EQ(7, val2);
  EXPECT_EQ(5, val3);
  EXPECT_EQ(string("[]"), L.str());
  EXPECT_EQ(0, L.length());
}

TEST(DLList, PopFirst)
{
  DLList L;
  int val1, val2, val3;
  L.append(5);
  L.append(7);
  L.append(3);

  val1 = L.pop(0);
  val2 = L.pop(0);
  val3 = L.pop(0);

  EXPECT_EQ(5, val1);
  EXPECT_EQ(7, val2);
  EXPECT_EQ(3, val3);
  EXPECT_EQ(string("[]"), L.str());
  EXPECT_EQ(0, L.length());
}

TEST(DLList, PopMiddle)
{
  DLList L;
  int val1, val2, val3;
  L.append(5);
  L.append(7);
  L.append(3);
  L.append(4);
  L.append(9);

  val1 = L.pop(3);
  val2 = L.pop(1);
  val3 = L.pop(1);

  EXPECT_EQ(4, val1);
  EXPECT_EQ(7, val2);
  EXPECT_EQ(3, val3);
  EXPECT_EQ(string("[5, 9]"), L.str());
  EXPECT_EQ(2, L.length());
}

TEST(DLList, InsertMultiple)
{
  DLList s;
  s.insert(0, 5);
  s.insert(1, 7);
  s.insert(2, 6);
  s.insert(3, 4);
  s.insert(4, 9);
  s.insert(3, 10);
  s.insert(1, 11);
  s.insert(5, 12);
  s.insert(0, 13);
  s.insert(1, 14);
  EXPECT_EQ(string("[13, 14, 5, 11, 7, 6, 10, 12, 4, 9]"), s.str());
}

TEST(DLList, Assign)
{
  DLList s;
  s.insert(0, 5);
  s.insert(1, 7);
  s.insert(2, 6);
  s.insert(3, 4);
  s.insert(4, 9);
  for (int i=0; i < 5; i++) {
    s[i] = 5-i;
  }
  EXPECT_EQ(string("[5, 4, 3, 2, 1]"), s.str());
}

TEST(DLList, PopEmpty)
{
  DLList L;
  EXPECT_THROW(L.pop(), IndexError);
}

TEST(DLList, PopEmptyInOut)
{
  DLList L;
  L.append(5);
  L.pop();
  EXPECT_THROW(L.pop(), IndexError);
}

TEST(DLList, IterThree)
{
  DLList L;
  L.append(0);
  L.append(1);
  L.append(2);

  for (int i = 0; i < L.length(); i++) {
    EXPECT_EQ(i, L.next());
  }
  EXPECT_THROW(L.next(), StopIteration);
  for (int i = 0; i < L.length(); i++) {
    EXPECT_EQ(i, L.next());
  }
}

TEST(DLList, CopyConstructor1)
{
  DLList L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList L2(L);
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLList, CopyConstructorNext)
{
  DLList L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList L2(L);
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2.next());
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLList, CopyConstructorValTest)
{
  DLList L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList L2(L);
  // Change all the values in L before checking copied values in L2
  for (int i=0; i<5; i++) {
    L[i] = 10 + i;
  }
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLList, Assignment1)
{
  DLList L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList L2;
  L2 = L;
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLList, AssignmentValTest)
{
  DLList L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList L2;
  L2 = L;
  // Change all the values in L before checking copied values in L2
  for (int i=0; i<5; i++) {
    L[i] = 10 + i;
  }
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLList, StreamOverload)
{
  stringstream s;
  DLList L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  s << L;
  EXPECT_EQ(string("[2, 1, 0, -1, -2]"), s.str());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#include <gtest/gtest.h>
#include "DLList.h"
#include <iostream>
#include <sstream>

using namespace std;

TEST(DLListint, EmptyConstructor) {
// create empty queue and verify string representation
	DLList<int> L;
	EXPECT_EQ(0, L.length());
	EXPECT_EQ(string("[]"), L.str());
}

TEST(DLListint, AppendOne) {
  DLList<int> L;
  L.append(5);
  EXPECT_EQ(string("[5]"), L.str());

  DLList<int> T;
  T.append(-10);
  EXPECT_EQ(string("[-10]"), T.str());
}

TEST(DLListint, InsertOne) {
  DLList<int> L;
  L.insert(0, 5);
  EXPECT_EQ(string("[5]"), L.str());

  DLList<int> T;
  T.insert(0, -10);
  EXPECT_EQ(string("[-10]"), T.str());
}

TEST(DLListint, AppendTwo) {
  DLList<int> L;
  L.append(5);
  L.append(-10);
  EXPECT_EQ(string("[5, -10]"), L.str());
}

TEST(DLListint, InsertTwoAtHead) {
  DLList<int> L;
  L.insert(0, 5);
  L.insert(0, -10);
  EXPECT_EQ(string("[-10, 5]"), L.str());
}

TEST(DLListint, InsertTwoInOrder) {
  DLList<int> L;
  L.insert(0, 5);
  L.insert(1, -10);
  EXPECT_EQ(string("[5, -10]"), L.str());
}

TEST(DLListint, AppendThree) {
  DLList<int> L;
  L.append(5);
  L.append(-10);
  L.append(7);
  EXPECT_EQ(string("[5, -10, 7]"), L.str());
}

TEST(DLListint, InsertThreeAtHead) {
  DLList<int> L;
  L.insert(0, 5);
  L.insert(0, -10);
  L.insert(0, 7);
  EXPECT_EQ(string("[7, -10, 5]"), L.str());
}

TEST(DLListint, AppendThreeInsertMiddle) {
  DLList<int> L;
  L.append(5);
  L.append(-10);
  L.append(7);
  L.insert(2, 1);
  EXPECT_EQ(string("[5, -10, 1, 7]"), L.str());

  DLList<int> T;
  T.append(5);
  T.append(-10);
  T.append(7);
  T.insert(1, 1);
  EXPECT_EQ(string("[5, 1, -10, 7]"), T.str());
}

TEST(DLListint, AccessAscending)
{
  DLList<int> L;
  for (int i = 0; i < 5; i++) {
    L.insert(i, i);
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(i, L[i]);
  }
}

TEST(DLListint, AccessDescending)
{
  DLList<int> L;
  for (int i = 0; i < 5; i++) {
    L.insert(i, 5-i);
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(5-i, L[i]);
  }
}

TEST(DLListint, PopOnly)
{
  int val;
  DLList<int> L;
  L.append(5);
  val = L.pop();
  EXPECT_EQ(5, val);
  EXPECT_EQ(string("[]"), L.str());
  EXPECT_EQ(0, L.length());
}

TEST(DLListint, PopLast)
{
  DLList<int> L;
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

TEST(DLListint, PopFirst)
{
  DLList<int> L;
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

TEST(DLListint, PopMiddle)
{
  DLList<int> L;
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

TEST(DLListint, InsertMultiple)
{
  DLList<int> L;
  L.insert(0, 5);
  L.insert(1, 7);
  L.insert(2, 6);
  L.insert(3, 4);
  L.insert(4, 9);
  L.insert(3, 10);
  L.insert(1, 11);
  L.insert(5, 12);
  L.insert(0, 13);
  L.insert(1, 14);
  EXPECT_EQ(string("[13, 14, 5, 11, 7, 6, 10, 12, 4, 9]"), L.str());
}

TEST(DLListint, Assign)
{
  DLList<int> L;
  L.insert(0, 5);
  L.insert(1, 7);
  L.insert(2, 6);
  L.insert(3, 4);
  L.insert(4, 9);
  for (int i=0; i < 5; i++) {
    L[i] = 5-i;
  }
  EXPECT_EQ(string("[5, 4, 3, 2, 1]"), L.str());
}

TEST(DLListint, PopEmpty)
{
  DLList<int> L;
  EXPECT_THROW(L.pop(), IndexError);
}

TEST(DLListint, PopEmptyInOut)
{
  DLList<int> L;
  L.append(5);
  L.pop();
  EXPECT_THROW(L.pop(), IndexError);
}

TEST(DLListint, IterThree)
{
  DLList<int> L;
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

TEST(DLListint, CopyConstructor1)
{
  DLList<int> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<int> L2(L);
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLListint, CopyConstructorNext)
{
  DLList<int> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<int> L2(L);
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2.next());
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLListint, CopyConstructorValTest)
{
  DLList<int> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<int> L2(L);
  // Change all the values in L before checking copied values in L2
  for (int i=0; i<5; i++) {
    L[i] = 10 + i;
  }
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLListint, Assignment1)
{
  DLList<int> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<int> L2;
  L2 = L;
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLListint, AssignmentValTest)
{
  DLList<int> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<int> L2;
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

TEST(DLListint, StreamOverload)
{
  stringstream s;
  DLList<int> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  s << L;
  EXPECT_EQ(string("[2, 1, 0, -1, -2]"), L.str());
}

TEST(DLListdouble, EmptyConstructor) {
// create empty queue and verify string representation
	DLList<double> L;
	EXPECT_EQ(0, L.length());
	EXPECT_EQ(string("[]"), L.str());
}

TEST(DLListdouble, AppendOne) {
  DLList<double> L;
  L.append(5);
  EXPECT_EQ(string("[5]"), L.str());

  DLList<double> T;
  T.append(-10);
  EXPECT_EQ(string("[-10]"), T.str());
}

TEST(DLListdouble, InsertOne) {
  DLList<double> L;
  L.insert(0, 5);
  EXPECT_EQ(string("[5]"), L.str());

  DLList<double> T;
  T.insert(0, -10);
  EXPECT_EQ(string("[-10]"), T.str());
}

TEST(DLListdouble, AppendTwo) {
  DLList<double> L;
  L.append(5);
  L.append(-10);
  EXPECT_EQ(string("[5, -10]"), L.str());
}

TEST(DLListdouble, InsertTwoAtHead) {
  DLList<double> L;
  L.insert(0, 5);
  L.insert(0, -10);
  EXPECT_EQ(string("[-10, 5]"), L.str());
}

TEST(DLListdouble, InsertTwoInOrder) {
  DLList<double> L;
  L.insert(0, 5);
  L.insert(1, -10);
  EXPECT_EQ(string("[5, -10]"), L.str());
}

TEST(DLListdouble, AppendThree) {
  DLList<double> L;
  L.append(5);
  L.append(-10);
  L.append(7);
  EXPECT_EQ(string("[5, -10, 7]"), L.str());
}

TEST(DLListdouble, InsertThreeAtHead) {
  DLList<double> L;
  L.insert(0, 5);
  L.insert(0, -10);
  L.insert(0, 7);
  EXPECT_EQ(string("[7, -10, 5]"), L.str());
}

TEST(DLListdouble, AppendThreeInsertMiddle) {
  DLList<double> L;
  L.append(5);
  L.append(-10);
  L.append(7);
  L.insert(2, 1);
  EXPECT_EQ(string("[5, -10, 1, 7]"), L.str());

  DLList<double> T;
  T.append(5);
  T.append(-10);
  T.append(7);
  T.insert(1, 1);
  EXPECT_EQ(string("[5, 1, -10, 7]"), T.str());
}

TEST(DLListdouble, AccessAscending)
{
  DLList<double> L;
  for (int i = 0; i < 5; i++) {
    L.insert(i, i);
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(i, L[i]);
  }
}

TEST(DLListdouble, AccessDescending)
{
  DLList<double> L;
  for (int i = 0; i < 5; i++) {
    L.insert(i, 5-i);
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(5-i, L[i]);
  }
}

TEST(DLListdouble, PopOnly)
{
  int val;
  DLList<double> L;
  L.append(5);
  val = L.pop();
  EXPECT_EQ(5, val);
  EXPECT_EQ(string("[]"), L.str());
  EXPECT_EQ(0, L.length());
}

TEST(DLListdouble, PopLast)
{
  DLList<double> L;
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

TEST(DLListdouble, PopFirst)
{
  DLList<double> L;
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

TEST(DLListdouble, PopMiddle)
{
  DLList<double> L;
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

TEST(DLListdouble, InsertMultiple)
{
  DLList<double> L;
  L.insert(0, 5);
  L.insert(1, 7);
  L.insert(2, 6);
  L.insert(3, 4);
  L.insert(4, 9);
  L.insert(3, 10);
  L.insert(1, 11);
  L.insert(5, 12);
  L.insert(0, 13);
  L.insert(1, 14);
  EXPECT_EQ(string("[13, 14, 5, 11, 7, 6, 10, 12, 4, 9]"), L.str());
}

TEST(DLListdouble, Assign)
{
  DLList<double> L;
  L.insert(0, 5);
  L.insert(1, 7);
  L.insert(2, 6);
  L.insert(3, 4);
  L.insert(4, 9);
  for (int i=0; i < 5; i++) {
    L[i] = 5-i;
  }
  EXPECT_EQ(string("[5, 4, 3, 2, 1]"), L.str());
}

TEST(DLListdouble, PopEmpty)
{
  DLList<double> L;
  EXPECT_THROW(L.pop(), IndexError);
}

TEST(DLListdouble, PopEmptyInOut)
{
  DLList<double> L;
  L.append(5);
  L.pop();
  EXPECT_THROW(L.pop(), IndexError);
}

TEST(DLListdouble, IterThree)
{
  DLList<double> L;
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

TEST(DLListdouble, CopyConstructor1)
{
  DLList<double> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<double> L2(L);
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLListdouble, CopyConstructorNext)
{
  DLList<double> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<double> L2(L);
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2.next());
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLListdouble, CopyConstructorValTest)
{
  DLList<double> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<double> L2(L);
  // Change all the values in L before checking copied values in L2
  for (int i=0; i<5; i++) {
    L[i] = 10 + i;
  }
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLListdouble, Assignment1)
{
  DLList<double> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<double> L2;
  L2 = L;
  for (int i=0; i<5; i++) {
    EXPECT_EQ(2-i, L2[i]);
  }
  EXPECT_EQ(5, L2.length());
}

TEST(DLListdouble, AssignmentValTest)
{
  DLList<double> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  DLList<double> L2;
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

TEST(DLListdouble, StreamOverload)
{
  stringstream s;
  DLList<double> L;
  for (int i=0; i<5; i++) {
    L.append(2-i);
  }
  s << L;
  EXPECT_EQ(string("[2, 1, 0, -1, -2]"), L.str());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

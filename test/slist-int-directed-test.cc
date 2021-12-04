//========================================================================
// slist-int-directed-test.cc
//========================================================================
// This file contains directed tests for SListInt functions.

#include "SListInt.h"
#include "ece2400-stdlib.h"
#include <stdlib.h>

//------------------------------------------------------------------------
// test_case_1_push_front
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_1_push_front()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);

  ECE2400_CHECK_INT_EQ( lst.size(), 3 );

  int ref[] = { 10, 11, 12 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), ref[i] );
  }
}

//------------------------------------------------------------------------
// test_case_2_push_front_longer
//------------------------------------------------------------------------
// A test case that tests push front with more data.

void test_case_2_push_front_longer()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  for ( int i = 0; i < 12; i++ )
    lst.push_front(i);

  ECE2400_CHECK_INT_EQ( lst.size(), 12 );

  for ( int i = 0; i < 12; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), 12-i-1 );
  }
}

//------------------------------------------------------------------------
// test_case_3_copy
//------------------------------------------------------------------------
// A simple test case that tests copying lists

void test_case_3_copy()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  ECE2400_CHECK_INT_EQ( lst0.size(), 3 );

  // Call the copy constructor

  SListInt lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse_v1();

  // Verify list 0

  ECE2400_CHECK_INT_EQ( lst0.size(), 3 );

  int ref0[] = { 12, 11, 10 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst0.at(i), ref0[i] );
  }

  // Verify list 1

  ECE2400_CHECK_INT_EQ( lst1.size(), 3 );

  int ref1[] = { 10, 11, 12 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst1.at(i), ref1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_4_swap
//------------------------------------------------------------------------
// A simple test case that tests swapping lists

void test_case_4_swap()
{
  std::printf( "\n%s\n", __func__ );

  // List 0

  SListInt lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  ECE2400_CHECK_INT_EQ( lst0.size(), 3 );

  // List 1

  SListInt lst1;
  lst1.push_front(22);
  lst1.push_front(21);
  lst1.push_front(20);

  ECE2400_CHECK_INT_EQ( lst1.size(), 3 );

  // Swap lists

  lst0.swap( lst1 );

  // Verify list 0

  ECE2400_CHECK_INT_EQ( lst0.size(), 3 );

  int ref0[] = { 20, 21, 22 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst0.at(i), ref0[i] );
  }

  // Verify list 1

  ECE2400_CHECK_INT_EQ( lst1.size(), 3 );

  int ref1[] = { 10, 11, 12 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst1.at(i), ref1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_5_assign
//------------------------------------------------------------------------
// A simple test case that tests assigning lists

void test_case_5_assign()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  ECE2400_CHECK_INT_EQ( lst0.size(), 3 );

  // Call the default constructor

  SListInt lst1;

  // Call the assignment operator

  lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse_v1();

  // Verify list 0

  ECE2400_CHECK_INT_EQ( lst0.size(), 3 );

  int ref0[] = { 12, 11, 10 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst0.at(i), ref0[i] );
  }

  // Verify list 1

  ECE2400_CHECK_INT_EQ( lst1.size(), 3 );

  int ref1[] = { 10, 11, 12 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst1.at(i), ref1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_6_self_assign
//------------------------------------------------------------------------
// A corner test case to check self assignment works.

void test_case_6_self_assign()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);

  ECE2400_CHECK_INT_EQ( lst.size(), 3 );

  // Call the assignment operator

  lst = lst;

  // Verify list

  ECE2400_CHECK_INT_EQ( lst.size(), 3 );

  int ref[] = { 10, 11, 12 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), ref[i] );
  }
}

//------------------------------------------------------------------------
// test_case_7_reverse_v1
//------------------------------------------------------------------------
// A simple test case that tests reverse v1

void test_case_7_reverse_v1()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);
  lst.reverse_v1();

  ECE2400_CHECK_INT_EQ( lst.size(), 3 );

  int ref[] = { 12, 11, 10 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), ref[i] );
  }
}

//------------------------------------------------------------------------
// test_case_8_reverse_longer_v1
//------------------------------------------------------------------------
// A test case that tests reverse v1 with more data.

void test_case_8_reverse_longer_v1()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  for ( int i = 0; i < 12; i++ )
    lst.push_front(i);
  lst.reverse_v1();

  ECE2400_CHECK_INT_EQ( lst.size(), 12 );

  for ( int i = 0; i < 12; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), i );
  }
}

//------------------------------------------------------------------------
// test_case_9_reverse_reverse_v1
//------------------------------------------------------------------------
// A test case that calls reverse twice

void test_case_9_reverse_reverse_v1()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  for ( int i = 0; i < 12; i++ )
    lst.push_front(i);
  lst.reverse_v1();
  lst.reverse_v1();

  ECE2400_CHECK_INT_EQ( lst.size(), 12 );

  for ( int i = 0; i < 12; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), 12-i-1 );
  }
}

//------------------------------------------------------------------------
// test_case_10_reverse_v2
//------------------------------------------------------------------------
// A simple test case that tests reverse v2

void test_case_10_reverse_v2()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);
  lst.reverse_v2();

  ECE2400_CHECK_INT_EQ( lst.size(), 3 );

  int ref[] = { 12, 11, 10 };
  for ( int i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), ref[i] );
  }
}

//------------------------------------------------------------------------
// test_case_11_reverse_longer_v2
//------------------------------------------------------------------------
// A test case that tests reverse v2 with more data.

void test_case_11_reverse_longer_v2()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  for ( int i = 0; i < 12; i++ )
    lst.push_front(i);
  lst.reverse_v2();

  ECE2400_CHECK_INT_EQ( lst.size(), 12 );

  for ( int i = 0; i < 12; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), i );
  }
}

//------------------------------------------------------------------------
// test_case_12_reverse_reverse_v2
//------------------------------------------------------------------------
// A test case that calls reverse twice

void test_case_12_reverse_reverse_v2()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  for ( int i = 0; i < 12; i++ )
    lst.push_front(i);
  lst.reverse_v2();
  lst.reverse_v2();

  ECE2400_CHECK_INT_EQ( lst.size(), 12 );

  for ( int i = 0; i < 12; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), 12-i-1 );
  }
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : std::atoi( argv[1] );

  if ( ( __n <= 0 ) || ( __n == 1  ) ) test_case_1_push_front();
  if ( ( __n <= 0 ) || ( __n == 2  ) ) test_case_2_push_front_longer();
  if ( ( __n <= 0 ) || ( __n == 3  ) ) test_case_3_copy();
  if ( ( __n <= 0 ) || ( __n == 4  ) ) test_case_4_swap();
  if ( ( __n <= 0 ) || ( __n == 5  ) ) test_case_5_assign();
  if ( ( __n <= 0 ) || ( __n == 6  ) ) test_case_6_self_assign();
  if ( ( __n <= 0 ) || ( __n == 7  ) ) test_case_7_reverse_v1();
  if ( ( __n <= 0 ) || ( __n == 8  ) ) test_case_8_reverse_longer_v1();
  if ( ( __n <= 0 ) || ( __n == 9  ) ) test_case_9_reverse_reverse_v1();
  if ( ( __n <= 0 ) || ( __n == 10 ) ) test_case_10_reverse_v2();
  if ( ( __n <= 0 ) || ( __n == 11 ) ) test_case_11_reverse_longer_v2();
  if ( ( __n <= 0 ) || ( __n == 12 ) ) test_case_12_reverse_reverse_v2();

  printf( "\n" );
  return __failed;
}

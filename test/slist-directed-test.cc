//========================================================================
// slist-directed-test.cc
//========================================================================
// This file contains directed tests for List<T>-related functions.

#include "SList.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_1_push_front
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_1_push_front()
{
  std::printf( "\n%s\n", __func__ );

  SList<int> lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);

  int ref[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ ) {
    UTST_ASSERT_INT_EQ( lst.at(i), ref[i] );
  }
}

//------------------------------------------------------------------------
// test_case_2_reverse
//------------------------------------------------------------------------
// A simple test case that tests reverse

void test_case_2_reverse()
{
  std::printf( "\n%s\n", __func__ );

  SList<int> lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);
  lst.reverse();

  int ref[] = { 12, 11, 10 };
  for ( size_t i = 0; i < 3; i++ ) {
    UTST_ASSERT_INT_EQ( lst.at(i), ref[i] );
  }
}

//------------------------------------------------------------------------
// test_case_3_copy
//------------------------------------------------------------------------
// A simple test case that tests copying lists

void test_case_3_copy()
{
  std::printf( "\n%s\n", __func__ );

  SList<int> lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  // Call the copy constructor

  SList<int> lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  int ref0[] = { 12, 11, 10 };
  for ( size_t i = 0; i < 3; i++ ) {
    UTST_ASSERT_INT_EQ( lst0.at(i), ref0[i] );
  }

  // Verify list 1

  int ref1[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ ) {
    UTST_ASSERT_INT_EQ( lst1.at(i), ref1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_5_assign_self
//------------------------------------------------------------------------
// A simple test case that tests self assignment.

void test_case_5_assign_self()
{
  std::printf( "\n%s\n", __func__ );

  // Create two lists

  SList<int> lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  SList<int> lst1;
  lst1.push_front(22);
  lst1.push_front(21);
  lst1.push_front(20);

  // Call the assignment operator

  lst1 = lst0;

  // Push front more values into lst0

  lst0.push_front(9);
  lst0.push_front(8);
  lst0.push_front(7);

  // Verify list 0

  int ref0[] = { 7, 8, 9, 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ ) {
    UTST_ASSERT_INT_EQ( lst0.at(i), ref0[i] );
  }

  // Verify list 1

  int ref1[] = { 20, 21, 22 };
  for ( size_t i = 0; i < 3; i++ ) {
    UTST_ASSERT_INT_EQ( lst1.at(i), ref1[i] );
  }
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_push_front();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_reverse();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_copy();
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_4_assign();
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_5_assign_self();

  return 0;
}

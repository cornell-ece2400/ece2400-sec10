//========================================================================
// slist-spoly-directed-test.cc
//========================================================================
// This file contains directed tests for static polymorphic list.

#include "SListSpoly.h"
#include "utst.h"
#include <complex>

//------------------------------------------------------------------------
// test_case_1_push_front
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_1_push_front()
{
  std::printf( "\n%s\n", __func__ );

  SListSpoly<int> lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);

  int ref[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_INT_EQ( lst.at(i), ref[i] );
}

//------------------------------------------------------------------------
// test_case_2_reverse
//------------------------------------------------------------------------
// A simple test case that tests reverse

void test_case_2_reverse()
{
  std::printf( "\n%s\n", __func__ );

  SListSpoly<int> lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);
  lst.reverse();

  int ref[] = { 12, 11, 10 };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_INT_EQ( lst.at(i), ref[i] );
}

//------------------------------------------------------------------------
// test_case_3_copy
//------------------------------------------------------------------------
// A simple test case that tests copying lists

void test_case_3_copy()
{
  std::printf( "\n%s\n", __func__ );

  SListSpoly<int> lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  // Call the copy constructor

  SListSpoly<int> lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  int ref0[] = { 12, 11, 10 };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_INT_EQ( lst0.at(i), ref0[i] );

  // Verify list 1

  int ref1[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_INT_EQ( lst1.at(i), ref1[i] );
}

//------------------------------------------------------------------------
// test_case_4_assign
//------------------------------------------------------------------------
// A simple test case that tests assigning lists

void test_case_4_assign()
{
  std::printf( "\n%s\n", __func__ );

  SListSpoly<int> lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  // Call the default constructor

  SListSpoly<int> lst1;

  // Call the assignment operator

  lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  int ref0[] = { 12, 11, 10 };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_INT_EQ( lst0.at(i), ref0[i] );

  // Verify list 1

  int ref1[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_INT_EQ( lst1.at(i), ref1[i] );
}

//------------------------------------------------------------------------
// test_case_5_assign_self
//------------------------------------------------------------------------
// A simple test case that tests self assignment.

void test_case_5_assign_self()
{
  std::printf( "\n%s\n", __func__ );

  // Create two lists

  SListSpoly<int> lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  SListSpoly<int> lst1;
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
  for ( size_t i = 0; i < 6; i++ )
    UTST_ASSERT_INT_EQ( lst0.at(i), ref0[i] );

  // Verify list 1

  int ref1[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_INT_EQ( lst1.at(i), ref1[i] );
}

//------------------------------------------------------------------------
// test_case_6_double
//------------------------------------------------------------------------
// A simple test case that tests push front doubles.

void test_case_6_double()
{
  std::printf( "\n%s\n", __func__ );

  SListSpoly<double> lst;
  lst.push_front( 1.2 );
  lst.push_front( 1.1 );
  lst.push_front( 1.0 );

  double ref[] = { 1.0, 1.1, 1.2 };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst.at(i) == ref[i] );
}

//------------------------------------------------------------------------
// test_case_7_complex
//------------------------------------------------------------------------
// A simple test case that tests push front complex numbers.

void test_case_7_complex()
{
  std::printf( "\n%s\n", __func__ );

  typedef std::complex<double> cmplx;
  SListSpoly<cmplx> lst;
  lst.push_front( cmplx(1.2,2.0) );
  lst.push_front( cmplx(1.1,2.1) );
  lst.push_front( cmplx(1.0,2.2) );

  cmplx ref[] = { cmplx(1.0,2.2), cmplx(1.1,2.1), cmplx(1.2,2.0) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst.at(i) == ref[i] );
}

//------------------------------------------------------------------------
// test_case_8_list_list
//------------------------------------------------------------------------
// A test acse for a list of lists.

void test_case_8_list_list()
{
  std::printf( "\n%s\n", __func__ );

  SListSpoly<SListSpoly<int>> lst;
  lst.push_front( SListSpoly<int>() );
  lst.push_front( SListSpoly<int>() );
  lst.push_front( SListSpoly<int>() );

  lst.at(0).push_front(12);
  lst.at(0).push_front(11);
  lst.at(0).push_front(10);

  lst.at(1).push_front(21);
  lst.at(1).push_front(20);

  lst.at(2).push_front(30);

  UTST_ASSERT_TRUE( lst.at(0).at(0) == 10 );
  UTST_ASSERT_TRUE( lst.at(0).at(1) == 11 );
  UTST_ASSERT_TRUE( lst.at(0).at(2) == 12 );
  UTST_ASSERT_TRUE( lst.at(1).at(0) == 20 );
  UTST_ASSERT_TRUE( lst.at(1).at(1) == 21 );
  UTST_ASSERT_TRUE( lst.at(2).at(0) == 30 );
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
  if ( ( __n == 0 ) || ( __n == 5 ) ) test_case_5_assign_self();
  if ( ( __n == 0 ) || ( __n == 6 ) ) test_case_6_double();
  if ( ( __n == 0 ) || ( __n == 7 ) ) test_case_7_complex();
  if ( ( __n == 0 ) || ( __n == 8 ) ) test_case_8_list_list();

  return 0;
}

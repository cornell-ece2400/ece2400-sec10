//========================================================================
// list-dpoly-directed-test.cc
//========================================================================
// This file contains directed tests for dynamic polymorphic list.

#include "SListDpoly.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_1_push_front
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_1_push_front()
{
  std::printf( "\n%s\n", __func__ );

  SListDpoly lst;
  lst.push_front( Integer(12) );
  lst.push_front( Integer(11) );
  lst.push_front( Integer(10) );

  Integer ref[] = { Integer(10), Integer(11), Integer(12) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst.at(i) == ref[i] );
}

//------------------------------------------------------------------------
// test_case_2_reverse
//------------------------------------------------------------------------
// A simple test case that tests reverse

void test_case_2_reverse()
{
  std::printf( "\n%s\n", __func__ );

  SListDpoly lst;
  lst.push_front( Integer(12) );
  lst.push_front( Integer(11) );
  lst.push_front( Integer(10) );
  lst.reverse();

  Integer ref[] = { Integer(12), Integer(11), Integer(10) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst.at(i) == ref[i] );
}

//------------------------------------------------------------------------
// test_case_3_copy
//------------------------------------------------------------------------
// A simple test case that tests copying lists

void test_case_3_copy()
{
  std::printf( "\n%s\n", __func__ );

  SListDpoly lst0;
  lst0.push_front( Integer(12) );
  lst0.push_front( Integer(11) );
  lst0.push_front( Integer(10) );

  // Call the copy constructor

  SListDpoly lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  Integer ref0[] = { Integer(12), Integer(11), Integer(10) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst0.at(i) == ref0[i] );

  // Verify list 1

  Integer ref1[] = { Integer(10), Integer(11), Integer(12) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst1.at(i) == ref1[i] );
}

//------------------------------------------------------------------------
// test_case_4_assign
//------------------------------------------------------------------------
// A simple test case that tests assigning lists

void test_case_4_assign()
{
  std::printf( "\n%s\n", __func__ );

  SListDpoly lst0;
  lst0.push_front( Integer(12) );
  lst0.push_front( Integer(11) );
  lst0.push_front( Integer(10) );

  // Call the default constructor

  SListDpoly lst1;

  // Call the assignment operator

  lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  Integer ref0[] = { Integer(12), Integer(11), Integer(10) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst0.at(i) == ref0[i] );

  // Verify list 1

  Integer ref1[] = { Integer(10), Integer(11), Integer(12) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst1.at(i) == ref1[i] );
}

//------------------------------------------------------------------------
// test_case_5_assign_self
//------------------------------------------------------------------------
// A simple test case that tests self assignment.

void test_case_5_assign_self()
{
  std::printf( "\n%s\n", __func__ );

  // Create two lists

  SListDpoly lst0;
  lst0.push_front( Integer(12) );
  lst0.push_front( Integer(11) );
  lst0.push_front( Integer(10) );

  SListDpoly lst1;
  lst1.push_front( Integer(22) );
  lst1.push_front( Integer(21) );
  lst1.push_front( Integer(20) );

  // Call the assignment operator

  lst1 = lst0;

  // Push front more values into lst0

  lst0.push_front( Integer(9) );
  lst0.push_front( Integer(8) );
  lst0.push_front( Integer(7) );

  // Verify list 0

  Integer ref0[] = { Integer(7),  Integer(8),  Integer(9),
                     Integer(10), Integer(11), Integer(12) };
  for ( size_t i = 0; i < 6; i++ )
    UTST_ASSERT_TRUE( lst0.at(i) == ref0[i] );

  // Verify list 1

  Integer ref1[] = { Integer(10), Integer(11), Integer(12) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst1.at(i) == ref1[i] );
}

//------------------------------------------------------------------------
// test_case_6_double
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_6_double()
{
  std::printf( "\n%s\n", __func__ );

  SListDpoly lst;
  lst.push_front( Double(1.2) );
  lst.push_front( Double(1.1) );
  lst.push_front( Double(1.0) );

  Double ref[] = { Double(1.0), Double(1.1), Double(1.2) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst.at(i) == ref[i] );
}

//------------------------------------------------------------------------
// test_case_7_complex
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_7_complex()
{
  std::printf( "\n%s\n", __func__ );

  SListDpoly lst;
  lst.push_front( Complex(1.2,2.0) );
  lst.push_front( Complex(1.1,2.1) );
  lst.push_front( Complex(1.0,2.2) );

  Complex ref[] = { Complex(1.0,2.2), Complex(1.1,2.1), Complex(1.2,2.0) };
  for ( size_t i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( lst.at(i) == ref[i] );
}

//------------------------------------------------------------------------
// test_case_8_mix
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_8_mix()
{
  std::printf( "\n%s\n", __func__ );

  SListDpoly lst0;
  lst0.push_front( Integer(12)      );
  lst0.push_front( Double(1.2)      );
  lst0.push_front( Complex(1.0,2.2) );

  UTST_ASSERT_TRUE( lst0.at(0) == Complex(1.0,2.2) );
  UTST_ASSERT_TRUE( lst0.at(1) == Double(1.2) );
  UTST_ASSERT_TRUE( lst0.at(2) == Integer(12) );

  SListDpoly lst1 = lst0;

  lst0.reverse();

  UTST_ASSERT_TRUE( lst0.at(0) == Integer(12) );
  UTST_ASSERT_TRUE( lst0.at(1) == Double(1.2) );
  UTST_ASSERT_TRUE( lst0.at(2) == Complex(1.0,2.2) );

  UTST_ASSERT_TRUE( lst1.at(0) == Complex(1.0,2.2) );
  UTST_ASSERT_TRUE( lst1.at(1) == Double(1.2) );
  UTST_ASSERT_TRUE( lst1.at(2) == Integer(12) );

  lst1 = lst0;

  UTST_ASSERT_TRUE( lst0.at(0) == Integer(12) );
  UTST_ASSERT_TRUE( lst0.at(1) == Double(1.2) );
  UTST_ASSERT_TRUE( lst0.at(2) == Complex(1.0,2.2) );

  UTST_ASSERT_TRUE( lst1.at(0) == Integer(12) );
  UTST_ASSERT_TRUE( lst1.at(1) == Double(1.2) );
  UTST_ASSERT_TRUE( lst1.at(2) == Complex(1.0,2.2) );
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
  if ( ( __n == 0 ) || ( __n == 8 ) ) test_case_8_mix();

  return 0;
}

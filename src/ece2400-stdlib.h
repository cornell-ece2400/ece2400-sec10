//========================================================================
// ece2400-stdlib.h
//========================================================================
// Standard library for ece2400.
//
// DO NOT CHANGE THE FOLLOWING CODE!
//
// Author: Yanghui Ou, Peitian Pan
//   Date: Oct 13, 2020

#ifndef ECE2400_STDLIB_H
#define ECE2400_STDLIB_H

#include <cstdio>
#include <cmath>

#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

typedef unsigned int uint_t;

//========================================================================
// ECE2400_CHECK_* macros
//========================================================================

// __n  > 0: display full [ passed ] line
// __n == 0: do not display anything for passed case
// __n  < 0: display a dot for passed case
extern int __n;

// The status of the current test file. Any failed check sets
// this variable to 1.
extern int __failed;

// Temporary variable to save the condition so that we don't
// evaluate the given expressions multiple times.
extern int    __failure_condition;
extern int    __int_expr0;
extern int    __int_expr1;
extern double __double_expr0;
extern double __double_expr1;

// Check macro helper functions
const char* __ece2400_get_file_name(const char*);
void  __ece2400_fail(const char*, int, const char*);
void  __ece2400_check_and_print_uniop(const char*, int, const char*);
void  __ece2400_check_and_print_int_binop(const char*, int, const char*, const char*);
void  __ece2400_check_and_print_double_binop(const char*, int, const char*, const char*);

//------------------------------------------------------------------------
// ECE2400_CHECK_FAIL()
//------------------------------------------------------------------------
// Unconditionally fail a test case.

#define ECE2400_CHECK_FAIL() \
  __ece2400_fail( __FILE__, __LINE__, "ECE2400_CHECK_FAIL" ); \
  return;

//------------------------------------------------------------------------
// ECE2400_CHECK_TRUE( expr_ )
//------------------------------------------------------------------------
// Checks to see if the expression is true.

#define ECE2400_CHECK_TRUE( expr_ ) \
  __int_expr0 = expr_; \
  __failure_condition = !__int_expr0; \
  __ece2400_check_and_print_uniop( __FILE__, __LINE__, #expr_ ); \
  if ( __failure_condition ) return;

//------------------------------------------------------------------------
// ECE2400_CHECK_FALSE( expr_ )
//------------------------------------------------------------------------
// Checks to see if the expression is false.

#define ECE2400_CHECK_FALSE( expr_ ) \
  __int_expr0 = expr_; \
  __failure_condition = __int_expr0; \
  __ece2400_check_and_print_uniop( __FILE__, __LINE__, #expr_ ); \
  if ( __failure_condition ) return;

//------------------------------------------------------------------------
// ECE2400_CHECK_INT_EQ( expr0_, expr1_ )
//------------------------------------------------------------------------
// Checks to see if the two expressions are equal using the != operator.

#define ECE2400_CHECK_INT_EQ( expr0_, expr1_ ) {\
  __int_expr0 = (int)(expr0_); \
  __int_expr1 = (int)(expr1_); \
  __failure_condition = __int_expr0 != __int_expr1; \
  __ece2400_check_and_print_int_binop( __FILE__, __LINE__, #expr0_, #expr1_ ); \
  if ( __failure_condition ) return;}

//------------------------------------------------------------------------
// ECE2400_CHECK_ARRAY_INT_EQ( expr0_, expr1_, size_ )
//------------------------------------------------------------------------
// Checks to see if the two arrays of integers are equal using the
// != operator.

#define ECE2400_CHECK_ARRAY_INT_EQ( expr0_, expr1_, size_ )             \
  for ( size_t i = 0; i < size_; i++ ) {                                \
    ECE2400_CHECK_INT_EQ( expr0_[i], expr1_[i] );                       \
  }

//------------------------------------------------------------------------
// ECE2400_CHECK_APPROX_EQ( expr0_, expr1_, pct_ )
//------------------------------------------------------------------------
// Checks to see if the two expressions are within percent of each other.

#define ECE2400_CHECK_APPROX_EQ( expr0_, expr1_, pct_ ) \
  __double_expr0 = expr0_; \
  __double_expr1 = expr1_; \
  __failure_condition = fabs( __double_expr0 - __double_expr1 ) > fabs( (double)(pct_) * __double_expr1 ); \
  __ece2400_check_and_print_double_binop( __FILE__, __LINE__, #expr0_, #expr1_ ); \
  if ( __failure_condition ) return;

//------------------------------------------------------------------------
// ECE2400_DEBUG( ... ) and ECE2400_DEBUG_NEWLINE
//------------------------------------------------------------------------
// Print out debug info when not in eval build. Note that debug info is
// only dumped to stdout when __n > 0 (i.e., we are looking at a specific
// test function).

#ifndef EVAL

#define ECE2400_DEBUG( ... ) \
  if ( __n > 0 ) { \
    std::printf(" - [ " YELLOW "-info-" RESET " ] File %s:%d: ", __ece2400_get_file_name(__FILE__), __LINE__); \
    std::printf(__VA_ARGS__); \
    std::printf("\n"); \
  }

#define ECE2400_DEBUG_ARRAY_INT( array_, size_ )                        \
  if ( __n > 0 ) {                                                      \
    std::printf(" - [ " YELLOW "-info-" RESET " ] %s:%d: %s = { ",      \
      __ece2400_get_file_name(__FILE__), __LINE__, #array_);            \
    for ( size_t i = 0; i < size_; i++ ) {                              \
      std::printf( "%d", array_[i] );                                   \
      if ( i != size_-1 )                                               \
        printf( ", " );                                                 \
    }                                                                   \
    std::printf(" }\n");                                                \
  }

#define ECE2400_DEBUG_NEWLINE \
  if ( __n > 0 ) { std::printf("\n"); }

#else

#define ECE2400_DEBUG( ... ) ;

#define ECE2400_DEBUG_ARRAY_INT( ... ) ;

#define ECE2400_DEBUG_NEWLINE ;

#endif // #ifndef EVAL

namespace ece2400
{
  //----------------------------------------------------------------------
  // sort
  //----------------------------------------------------------------------
  // A reference sorting function that sorts an array of integer in
  // ascending order.

  void sort( int* a, size_t size );

  //----------------------------------------------------------------------
  // mem_reset
  //----------------------------------------------------------------------
  // Resets the memory counter to 0.

  void mem_reset();

  //----------------------------------------------------------------------
  // timer_reset
  //----------------------------------------------------------------------
  // Resets the timer.

  void timer_reset();

  //----------------------------------------------------------------------
  // timer_get_elapsed
  //----------------------------------------------------------------------
  // Return the elapased time in seconds.

  double timer_get_elapsed();
}

#endif  // ECE2400_STDLIB_H

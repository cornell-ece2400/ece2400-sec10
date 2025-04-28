//========================================================================
// swap-directed-test.cc
//========================================================================
// This file contains directed tests for generic swap function

#include "ece2400-stdlib.h"
#include "swap.h"
#include <stdlib.h>

//------------------------------------------------------------------------
// test_case_1_swap_ints
//------------------------------------------------------------------------
// A simple test case that tests swaping ints

void test_case_1_swap_ints() {
  std::printf("\n%s\n", __func__);

  int a = 10;
  int b = 20;

  swap(a, b);

  ECE2400_CHECK_INT_EQ(a, 20);
  ECE2400_CHECK_INT_EQ(b, 10);
}

//------------------------------------------------------------------------
// test_case_2_swap_ptrs
//------------------------------------------------------------------------
// A simple test case that tests swaping pointers

void test_case_2_swap_ptrs() {
  std::printf("\n%s\n", __func__);

  int a = 10;
  int b = 20;

  int* ptr0 = &a;
  int* ptr1 = &b;

  swap(ptr0, ptr1);

  ECE2400_CHECK_INT_EQ(a, 10);
  ECE2400_CHECK_INT_EQ(b, 20);
  ECE2400_CHECK_INT_EQ(*ptr0, 20);
  ECE2400_CHECK_INT_EQ(*ptr1, 10);
}

//------------------------------------------------------------------------
// test_case_2_swap_structs
//------------------------------------------------------------------------
// A simple test case that tests swaping structs

struct Foo {
  Foo(int x_, int y_) {
    x = x_;
    y = y_;
  }
  int x;
  int y;
};

void test_case_3_swap_structs() {
  std::printf("\n%s\n", __func__);

  Foo a(10, 11);
  Foo b(20, 21);

  swap(a, b);

  ECE2400_CHECK_INT_EQ(a.x, 20);
  ECE2400_CHECK_INT_EQ(a.y, 21);
  ECE2400_CHECK_INT_EQ(b.x, 10);
  ECE2400_CHECK_INT_EQ(b.y, 11);
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main(int argc, char** argv) {
  __n = (argc == 1) ? 0 : std::atoi(argv[1]);

  if ((__n <= 0) || (__n == 1))
    test_case_1_swap_ints();
  if ((__n <= 0) || (__n == 2))
    test_case_2_swap_ptrs();
  if ((__n <= 0) || (__n == 3))
    test_case_3_swap_structs();

  printf("\n");
  return __failed;
}

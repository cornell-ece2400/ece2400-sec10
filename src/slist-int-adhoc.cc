//========================================================================
// slist-int-adhoc.c
//========================================================================

#include "SListInt.h"

int main( void )
{
  // Construct a list using default constructor

  SListInt lst;

  // Push front three items

  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);

  // Print the list

  lst.print();

  return 0;
}


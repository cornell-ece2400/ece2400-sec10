//========================================================================
// slist-dpoly-adhoc.c
//========================================================================

#include "SListDpoly.h"

int main( void )
{
  // Construct a list using default constructor

  SListDpoly lst;

  // Push front three items

  lst.push_front( Integer(12) );
  lst.push_front( Integer(11) );
  lst.push_front( Integer(10) );

  // Push front three items of a different type

  lst.push_front( Double(1.2) );
  lst.push_front( Double(1.1) );
  lst.push_front( Double(1.0) );

  // Print the list

  lst.print();

  return 0;
}


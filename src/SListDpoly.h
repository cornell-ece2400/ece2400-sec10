//========================================================================
// SListDpoly.h
//========================================================================
// Declarations for dynamic polymorphic singly linked list.

#ifndef SLIST_DPOLY_H
#define SLIST_DPOLY_H

#include "types-dpoly.h"
#include <cstddef>

class SListDpoly
{
  //----------------------------------------------------------------------
  // Constructor and destructor
  //----------------------------------------------------------------------

 public:

  SListDpoly();
  ~SListDpoly();

  //----------------------------------------------------------------------
  // Copy constructor and assignment operator
  //----------------------------------------------------------------------

 public:

  SListDpoly( const SListDpoly& lst );
  SListDpoly& operator=( const SListDpoly& lst );

  //----------------------------------------------------------------------
  // Member functions
  //----------------------------------------------------------------------

 public:

  void           push_front( const IObject& v );
  const IObject& at( size_t idx ) const;
  void           reverse();
  void           print() const;

  //----------------------------------------------------------------------
  // Private member functions and fields
  //----------------------------------------------------------------------

 private:

  struct Node                // nested struct declaration
  {
    IObject* obj_p;
    Node*    next_p;
  };

  Node* m_head_p;            // member field

};

#endif /* SLIST_DPOLY_H */


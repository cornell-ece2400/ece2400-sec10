//========================================================================
// SListSpoly.h
//========================================================================
// Declarations for static polymorphic singly linked list.

#ifndef SLIST_SPOLY_H
#define SLIST_SPOLY_H

#include <cstddef>

template < typename T >
class SListSpoly
{
  //----------------------------------------------------------------------
  // Constructor and destructor
  //----------------------------------------------------------------------

 public:

  SListSpoly();
  ~SListSpoly();

  //----------------------------------------------------------------------
  // Copy constructor and assignment operator
  //----------------------------------------------------------------------

 public:

  SListSpoly( const SListSpoly<T>& lst );
  SListSpoly& operator=( const SListSpoly<T>& lst );

  //----------------------------------------------------------------------
  // Member functions
  //----------------------------------------------------------------------

 public:

  void     push_front( const T& v );
  const T& at( size_t idx ) const;
  T&       at( size_t idx );
  void     reverse();
  void     print() const;

  //----------------------------------------------------------------------
  // Private member functions and fields
  //----------------------------------------------------------------------

 private:

  struct Node                // nested struct declaration
  {
    T     value;
    Node* next_p;
  };

  Node* m_head_p;            // member field

};

//------------------------------------------------------------------------
// Include inline and template definitions
//------------------------------------------------------------------------

#include "SListSpoly.inl"

#endif /* SLIST_SPOLY_H */


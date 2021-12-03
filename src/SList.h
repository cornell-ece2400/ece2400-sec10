//========================================================================
// SList.h
//========================================================================
// Declarations for SList<T>

#ifndef SLIST_H
#define SLIST_H

template < typename T >
class SList
{
  //----------------------------------------------------------------------
  // Constructor and destructor
  //----------------------------------------------------------------------

 public:

  SList();
  ~SList();

  //----------------------------------------------------------------------
  // Copy constructor, swap, assignment operator
  //----------------------------------------------------------------------

 public:

  SList( const SList& lst );
  void swap( SList& lst );
  SList& operator=( const SList& lst );

  //----------------------------------------------------------------------
  // Member functions
  //----------------------------------------------------------------------

 public:

  void     push_front( const T& v );
  int      size() const;
  const T& at( int idx ) const;
  T&       at( int idx );
  void     reverse_v1();
  void     reverse_v2();
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
// Include inline definitions
//------------------------------------------------------------------------

#include "SList.inl"

#endif /* SLIST_H */


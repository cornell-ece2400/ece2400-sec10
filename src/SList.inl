//========================================================================
// SList.cc
//========================================================================
// Implementation for List

#include <cstdio>

#include "SList.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// SList Default Constructor
//------------------------------------------------------------------------

template < typename T >
SList<T>::SList()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SList Destructor
//------------------------------------------------------------------------

template < typename T >
SList<T>::~SList()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement destructor
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SList Copy Constructor
//------------------------------------------------------------------------

template < typename T >
SList<T>::SList( const SList<T>& lst )
{
  // We must make sure head pointer is initialized correctly, otherwise
  // push_front will not work correctly.

  m_head_p = nullptr;

  // Iterate through each element of the given lst and use push_front to
  // add it to this list.

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // We now have all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();
}

//------------------------------------------------------------------------
// SList Swap
//------------------------------------------------------------------------

template < typename T >
void SList<T>::swap( SList<T>& lst )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement swap
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SList Overloaded Assignment Operator
//------------------------------------------------------------------------

template < typename T >
SList<T>& SList<T>::operator=( const SList<T>& lst )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement operator=
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  return *this;
}

//------------------------------------------------------------------------
// SList<T>::push_front
//------------------------------------------------------------------------

template < typename T >
void SList<T>::push_front( const T& v )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement push_front
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SList<T>::size
//------------------------------------------------------------------------

template < typename T >
int SList<T>::size() const
{
  int   size   = 0;
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    size++;
    curr_p = curr_p->next_p;
  }

  return size;
}

//------------------------------------------------------------------------
// SList<T>::at
//------------------------------------------------------------------------

template < typename T >
const T& SList<T>::at( int idx ) const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  return m_head_p->value;
}

//------------------------------------------------------------------------
// SList<T>::at
//------------------------------------------------------------------------

template < typename T >
T& SList<T>::at( int idx )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  return m_head_p->value;
}

//------------------------------------------------------------------------
// SList<T>::reverse_v1
//------------------------------------------------------------------------
// Pseudocode for this algorithm:
//
//  def reverse( x, n ):
//    for i in 0 to n/2:
//      swap( x[i], x[(n-1)-i] )
//

template < typename T >
void SList<T>::reverse_v1()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse_v1
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SList<T>::reverse_v2
//------------------------------------------------------------------------
// Steps for this algorithm:
//
//  1. Create temporary singly linked list
//  2. Push front all values from this list onto temporary list
//  3. Swap this list with the temporary list
//

template < typename T >
void SList<T>::reverse_v2()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse_v2
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SList<T>::print
//------------------------------------------------------------------------

template < typename T >
void SList<T>::print() const
{
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    std::printf( "%d ", curr_p->value );
    curr_p = curr_p->next_p;
  }
  std::printf( "\n" );
}


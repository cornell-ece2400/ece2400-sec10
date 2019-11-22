//========================================================================
// SListSpoly.inl
//========================================================================
// Implementation for static polymorphic singly linked list.

#include "SListSpoly.h"
#include "ece2400-stdlib.h"
#include <iostream>
#include <cassert>

//------------------------------------------------------------------------
// SListSpoly<T> Default Constructor
//------------------------------------------------------------------------

template < typename T >
SListSpoly<T>::SListSpoly()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListSpoly<T> Destructor
//------------------------------------------------------------------------

template < typename T >
SListSpoly<T>::~SListSpoly()
{
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
    m_head_p = temp_p;
  }
}

//------------------------------------------------------------------------
// SListSpoly<T> Copy Constructor
//------------------------------------------------------------------------

template < typename T >
SListSpoly<T>::SListSpoly( const SListSpoly<T>& lst )
{
  m_head_p = nullptr;

  // Push front all nodes from lst

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // Reverse list to get into proper order

  reverse();
}

//------------------------------------------------------------------------
// SListSpoly<T> Overloaded Assignment Operator
//------------------------------------------------------------------------

template < typename T >
SListSpoly<T>& SListSpoly<T>::operator=( const SListSpoly<T>& lst )
{
  // Delete all of the current nodes first

  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
    m_head_p = temp_p;
  }

  // Push front all nodes from lst

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // Reverse list to get into proper order

  reverse();
  return *this;
}

//------------------------------------------------------------------------
// SListSpoly<T>::push_front
//------------------------------------------------------------------------

template < typename T >
void SListSpoly<T>::push_front( const T& v )
{
  Node* new_node_p   = new Node;
  new_node_p->value  = v;
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListSpoly<T>::at
//------------------------------------------------------------------------

template < typename T >
const T& SListSpoly<T>::at( size_t idx ) const
{
  Node*  curr_p   = m_head_p;
  size_t curr_idx = 0;

  while ( curr_p != nullptr ) {
    if ( curr_idx == idx )
      return curr_p->value;
    curr_idx += 1;
    curr_p   = curr_p->next_p;
  }

  throw ece2400::OutOfRange( "SListDpoly::at(): index out of bound!" );
}

//------------------------------------------------------------------------
// SListSpoly<T>::at
//------------------------------------------------------------------------

template < typename T >
T& SListSpoly<T>::at( size_t idx )
{
  Node*  curr_p   = m_head_p;
  size_t curr_idx = 0;

  while ( curr_p != nullptr ) {
    if ( curr_idx == idx )
      return curr_p->value;
    curr_idx += 1;
    curr_p   = curr_p->next_p;
  }

  throw ece2400::OutOfRange( "SListDpoly::at(): index out of bound!" );
}

//------------------------------------------------------------------------
// SListSpoly<T>::reverse
//------------------------------------------------------------------------

template < typename T >
void SListSpoly<T>::reverse()
{
  size_t size   = 0;
  Node*  curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    size   += 1;
    curr_p = curr_p->next_p;
  }

  T* tmp = new T[size];

  size_t i = 0;
  curr_p   = m_head_p;
  while ( curr_p != nullptr ) {
    tmp[i++] = curr_p->value;
    curr_p = curr_p->next_p;
  }

  size_t j = size-1;
  curr_p   = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->value = tmp[j--];
    curr_p = curr_p->next_p;
  }

  delete[] tmp;
}

//------------------------------------------------------------------------
// SListSpoly<T>::print
//------------------------------------------------------------------------

template < typename T >
void SListSpoly<T>::print() const
{
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    std::cout << curr_p->value << " ";
    curr_p = curr_p->next_p;
  }
  std::cout << std::endl;
}


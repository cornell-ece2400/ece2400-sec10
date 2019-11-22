//========================================================================
// SListDpoly.cc
//========================================================================
// Implementation for dynamic polymorphic singly linked list.

#include "SListDpoly.h"
#include "ece2400-stdlib.h"
#include <cstdio>
#include <cassert>

//------------------------------------------------------------------------
// SListDpoly Default Constructor
//------------------------------------------------------------------------

SListDpoly::SListDpoly()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListDpoly Destructor
//------------------------------------------------------------------------

SListDpoly::~SListDpoly()
{
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p->obj_p;
    delete m_head_p;
    m_head_p = temp_p;
  }
}

//------------------------------------------------------------------------
// SListDpoly Copy Constructor
//------------------------------------------------------------------------

SListDpoly::SListDpoly( const SListDpoly& lst )
{
  m_head_p = nullptr;

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( *(curr_p->obj_p) );
    curr_p = curr_p->next_p;
  }

  reverse();
}

//------------------------------------------------------------------------
// SListDpoly Overloaded Assignment Operator
//------------------------------------------------------------------------

SListDpoly& SListDpoly::operator=( const SListDpoly& lst )
{
  if ( this != &lst ) {
    while ( m_head_p != nullptr ) {
      Node* temp_p = m_head_p->next_p;
      delete m_head_p->obj_p;
      delete m_head_p;
      m_head_p = temp_p;
    }

    m_head_p = nullptr;

    Node* curr_p = lst.m_head_p;
    while ( curr_p != nullptr ) {
      push_front( *(curr_p->obj_p) );
      curr_p = curr_p->next_p;
    }

    reverse();
  }
  return *this;
}

//------------------------------------------------------------------------
// SListDpoly::push_front
//------------------------------------------------------------------------

void SListDpoly::push_front( const IObject& v )
{
  Node* new_node_p   = new Node;
  new_node_p->obj_p  = v.clone();
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListDpoly::at
//------------------------------------------------------------------------

const IObject& SListDpoly::at( size_t idx ) const
{
  Node*  curr_p   = m_head_p;
  size_t curr_idx = 0;

  while ( curr_p != nullptr ) {
    if ( curr_idx == idx )
      return *(curr_p->obj_p);
    curr_idx += 1;
    curr_p   = curr_p->next_p;
  }

  throw ece2400::OutOfRange( "SListDpoly::at(): index out of bound!" );
}

//------------------------------------------------------------------------
// SListDpoly::reverse
//------------------------------------------------------------------------

void SListDpoly::reverse()
{
  size_t size   = 0;
  Node*  curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    size   += 1;
    curr_p = curr_p->next_p;
  }

  IObject** tmp = new IObject*[size];

  size_t i = 0;
  curr_p   = m_head_p;
  while ( curr_p != nullptr ) {
    tmp[i++] = curr_p->obj_p;
    curr_p = curr_p->next_p;
  }

  size_t j = size-1;
  curr_p   = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->obj_p = tmp[j--];
    curr_p = curr_p->next_p;
  }

  delete[] tmp;
}

//------------------------------------------------------------------------
// SListDpoly::print
//------------------------------------------------------------------------

void SListDpoly::print() const
{
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->obj_p->print();
    std::printf( " " );
    curr_p = curr_p->next_p;
  }
  std::printf( "\n" );
}


#include "vec.h"

// need to include template <class T> for all functions that use
// templates or functions of classes that use templates
template <class T>
void Vec<T>::create () {
  // initialize empty vector
  this->m_data = NULL;
  this->m_size = this->m_alloc = 0;
}


/*
 * This create function initializes the vector to a size of n, each having
 * a value of val.
*/
template <class T>
void Vec<T>::create (size_type n, const T& val) {
  this->m_data = new T[n];
  this->m_size = this->m_alloc = n;

  // storing the value of class T to populate the vector
  for ( size_type i = 0; i < this->m_size; i++ )
    this->m_data[i] = val;

}

/*
 * Assignment Operator Overloading
 * Given a const vector instance v, return a copy of the vector
 * and assign it to the l-value instance
*/
template <class T>
Vec<T>& Vec<T>::operator= (const Vec<T>& v) {
  // only assign if this vector is a different vector
  if ( this != &v ) {
    // delete data in current vector and copy the new vector into this vector
    delete [] m_data;
    this->copy(v);
  }

  // return the copy vector, which should be this
  return *this;
}


/*
 * Copy function Implementation
 * Copy the values of a vec into the current vec
*/
template <class T>
void Vec<T>::copy(const Vec<T>& v) {
  // first, initialize the current vec to have v's properties
  this->m_size = v->m_size;
  this->m_alloc = v->m_alloc;

  // set m_data size to m_alloc
  this->m_data = new T[this->m_alloc];

  // loop through only size, in case size is less than alloc
  for ( int i = 0; i < this->m_size; i++ )
    //this->m_data[i] = new T( v->m_data[i] ); // assuming, assignment operator DOES NOT create copy
    this->m_data[i] = v->m_data[i]; // assuming, assignment operator creates copy
}

/*
 * Push Back Implementation
 * push_back should add a new value to the end of the vector
*/
template <class T>
void Vec<T>::push_back (const T& val) {
  if ( m_size == m_alloc ) {
    // make bigger
    resize (this->m_alloc + 4);
  }

  // add val to back of vec
  this->m_size ++;
  this->m_data[this->m_size - 1] = val;
}


/*
 * Resize function Implementation
 * Resize the vector to given size.
 * If new size is smaller,
 * remove extra T objects starting from the back.
 * If new size is bigger,
 * add extra T objects with value given in second param, to back.
 * should not use push_back ...
*/
template <class T>
void Vec<T>::resize (size_type n, const T& fill_in_value) {

  // if n is bigger than m_alloc
  if ( n > this->m_alloc ) {
    Vec<T> temp = *this;
    this->clear ();
    this->m_alloc = n;
    this->m_size = temp.m_size;
    this->m_data = new T[n];

    // repopulate with original values
    for ( int i = 0; i < temp.m_size; i++ )
      this->m_data[i] = temp.m_data[i];

    // popululate extra values with fill_in_value
    for ( int i = temp.m_size; i < n; i++ )
      this->m_data[i] = fill_in_value;
  } else if (n < this->m_alloc){
    // if n is equal to m_alloc, do nothing.
    // if n < m_alloc, shrink
    this->m_size = n;
  }

}

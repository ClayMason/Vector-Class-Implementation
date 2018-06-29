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

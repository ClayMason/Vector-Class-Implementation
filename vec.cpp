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

}

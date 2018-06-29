#include "vec.h"

// need to include template <class T> for all functions that use
// templates or functions of classes that use templates
template <class T>
void Vec<T>::create () {
  // initialize empty vector
  this->m_data = NULL;
  this->m_size = this->m_alloc = 0;
}

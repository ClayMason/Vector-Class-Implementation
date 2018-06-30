#include "vec.h"
#include <iostream>

template <class T>
void print_vec (Vec<T>* vec) {
  std::cout << "vec: ";
  for ( unsigned int i = 0; i < vec->size(); i++ ) {
    std::cout << (*vec)[i] << " ";
  }
  std::cout << std::endl;
}

int main () {

  // Test vec class
  Vec<double> a;
  Vec<double> b(10, 4.4);
  print_vec(&b);

  return 0;
}

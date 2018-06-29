#include <iostream>
#include <vector>
#include <vec.h>

template <class T>
void print_vec (std::vector<T>* vec) {
  std::cout << "vec: ";
  for ( unsigned int i = 0; i < vec->size(); i++ ) {
    std::cout << (*vec)[i] << " ";
  }
  std::cout << std::endl;
}

int main () {

  // Test vec class

  return 0;
}

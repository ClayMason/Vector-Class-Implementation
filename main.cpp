#include <iostream>
#include <vector>

template <class T>
void print_vec (std::vector<T>* vec) {
  std::cout << "vec: ";
  for ( unsigned int i = 0; i < vec->size(); i++ ) {
    std::cout << (*vec)[i] << " ";
  }
  std::cout << std::endl;
}

int main () {

  std::cout << "Begin" << std::endl;
  std::vector<double> v(4, 0.0); // vector with 4 allocations of 0.0
  v[0] = 13.1; v[2] = 3.14;

  print_vec(&v);

  std::vector<double> u(v); // copy v into vector u
  u[2] = 6.5;
  u[3] = -4.8;

  std::cout << "----------" << std::endl;
  std::cout << "After" << std::endl;
  print_vec(&v);
  print_vec(&u);

  return 0;
}

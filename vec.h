#ifndef Vec_h_
#define Vec_h_

// templated class to specifiy what type of objects
// the Vec will store when initialized
template <class T> class Vec {

  public:
    // typedefs
    typedef unsigned int size_type;

    // constructors
    /*DEFAULT*/ Vec () { this->create(); }
    /*POPULATE ON INSTANTIATION*/ Vec (size_type n, const T& t= T()) { this->create(n, t); }
    /*COPY*/ Vec (const Vec& v) { copy(v); }
    Vec& operator= (const Vec& v); // overwrite assignment operator
    /*DECONSTRUCTOR*/ ~Vec() { delete [] m_data; }

    // member functions
    T& operator[] (size_type i) { return m_data[i]; } // define [] operator
    const T& operator[] (size_type i) const { return m_data[i]; } // define [] operator for const Vec
    void push_back(const T& t); // add to end of vector
    void resize(size_type n, const T& fill_in_value = T()); // to resize vector
    void clear () { delete [] m_data; create(); } // remove m_data from memory and make empty vector
    bool empty () const { return m_size == 0; }
    size_type size() const { return m_size; } // get the size of the vector

  private:
    // PRIVATE MEMBER FUNCTIONS
    void create ();
    void create (size_type n, const T& val);
    void copy (const Vec<T>& v);

    // PRIVATE MEMBER VARIABLES
    T* m_data;
    size_type m_size;
    size_type m_alloc;
};

// ==========================================================
// IMPLEMENTATION
// NOTE: Template functions must be defined in header files
// and not in separate implementation files.
// ==========================================================

typedef unsigned int size_type;

// need to include template <class T> for all functions that use
// templates or functions of classes that use templates
template <class T>
void Vec<T>::create () {
  // initialize empty vector
  this->m_data = 0;
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


#endif

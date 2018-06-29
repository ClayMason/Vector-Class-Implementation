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
    void clear () { delete [] m_data; create() } // remove m_data from memory and make empty vector
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

#endif

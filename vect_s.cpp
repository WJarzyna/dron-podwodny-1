#include "vect.cpp"

#define SIZE_INT 3


template class Vector<double,SIZE_INT>;

template std::ostream& operator << (std::ostream &str, const Vector<double,SIZE_INT> &V);
template std::istream& operator >> (std::istream &str, Vector<double,SIZE_INT> &V);


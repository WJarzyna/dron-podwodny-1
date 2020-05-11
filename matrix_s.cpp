#include "matrix.cpp"

#define SIZE_INT 3

template class Matrix<double,SIZE_INT>;


template std::ostream& operator << (std::ostream &str, const Matrix<double,SIZE_INT> &V);
template std::istream& operator >> (std::istream &str, Matrix<double,SIZE_INT> &V);

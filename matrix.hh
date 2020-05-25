#pragma once
#include "vect.hh"

template <class TYPE, unsigned SIZE>
class Matrix
{
  Vector<TYPE,SIZE> V[SIZE];
  TYPE det_lap_part(bool done[SIZE], int row);
public:
  
  const Vector<TYPE,SIZE> operator [] (int arg) const { return V[arg]; }
  Vector<TYPE,SIZE>& operator [] (int arg) { return V[arg]; }

  
  void transpose();
  void operator = (const Matrix<TYPE,SIZE> &B);
  void colswap(int cnum, const Vector<TYPE,SIZE> &col);

  TYPE det_lap();
  Vector<TYPE,SIZE> operator * (const Vector<TYPE,SIZE> &X);

  Matrix<TYPE,SIZE> operator * (const Matrix<TYPE,SIZE> &X);
};

template <class TYPE, unsigned SIZE>
std::ostream& operator << (std::ostream& str, const Matrix<TYPE,SIZE> &A);

template <class TYPE, unsigned SIZE>
std::istream& operator >> (std::istream &str, Matrix<TYPE,SIZE> &A);


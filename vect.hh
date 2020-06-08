#pragma once
#include <iostream>
#include <cmath>



template <class TYPE, unsigned SIZE>
class Vector
{
  inline static unsigned count=0;
  TYPE x[SIZE];
  
public:
  static unsigned vect_cnt(){return count;};
  Vector<TYPE,SIZE>(); 
  const TYPE operator [] (unsigned arg) const { return x[arg]; }
  TYPE& operator [] (unsigned arg) { return x[arg]; }

  Vector<TYPE,SIZE> operator = (const Vector<TYPE,SIZE> B);
  Vector<TYPE,SIZE> operator + (const Vector<TYPE,SIZE> B);
  Vector<TYPE,SIZE> operator += (const Vector<TYPE,SIZE> B);
  Vector<TYPE,SIZE> operator - ( const Vector<TYPE,SIZE> B);
  Vector<TYPE,SIZE> operator * ( const double mul);
  TYPE operator * ( const Vector<TYPE,SIZE> B);
  Vector<TYPE,SIZE> operator / ( const double div);

  
  double len();
  ~Vector(){--count;};
  
};

template <class TYPE, unsigned SIZE>
std::ostream& operator << (std::ostream &str, const Vector<TYPE,SIZE> &V);

template <class TYPE, unsigned SIZE>
std::istream& operator >> (std::istream &str, Vector<TYPE,SIZE> &V); 


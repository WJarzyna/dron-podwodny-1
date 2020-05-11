#include <iostream>
#include <cmath>



template <class TYPE, unsigned SIZE>
class Vector
{
  TYPE x[SIZE];
  
public:
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


};

template <class TYPE, unsigned SIZE>
std::ostream& operator << (std::ostream &str, const Vector<TYPE,SIZE> &V);

template <class TYPE, unsigned SIZE>
std::istream& operator >> (std::istream &str, Vector<TYPE,SIZE> &V); 


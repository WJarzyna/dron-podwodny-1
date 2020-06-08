#include "vect.hh"

template <class TYPE, unsigned SIZE>
Vector<TYPE,SIZE>::Vector()
{
  for (unsigned i=0;i<SIZE;i++) x[i]=0;
  count++;
}


template <class TYPE, unsigned SIZE>
std::ostream& operator << (std::ostream &str, const Vector<TYPE,SIZE> &V)
{
  for(unsigned i=0; i<SIZE; i++) str<<V[i]<<' ';
  return str;
}


template <class TYPE, unsigned SIZE>
std::istream& operator >> (std::istream &str, Vector<TYPE,SIZE> &V)
{
  for(unsigned i=0; i<SIZE; i++) str>>V[i];
  return str;
}

template <class TYPE, unsigned SIZE>
Vector<TYPE,SIZE> Vector<TYPE,SIZE>:: operator = ( const Vector<TYPE,SIZE> B)
{
 
  for (unsigned  i=0;i<SIZE;i++)  x[i]=B[i];
  return *this;
}



template <class TYPE, unsigned SIZE>
Vector<TYPE,SIZE> Vector<TYPE,SIZE>:: operator + ( const Vector<TYPE,SIZE> B)
{
  Vector<TYPE,SIZE> out;
  for (unsigned  i=0;i<SIZE;i++)  out[i]=x[i]+B[i];
  return out;
}

template <class TYPE, unsigned SIZE>
Vector<TYPE,SIZE> Vector<TYPE,SIZE>:: operator += ( const Vector<TYPE,SIZE> B)
{
 
  for (unsigned  i=0;i<SIZE;i++)  x[i]=x[i]+B[i];
  return *this;
}


template <class TYPE, unsigned SIZE>
Vector<TYPE,SIZE> Vector<TYPE,SIZE>::operator - ( const Vector<TYPE,SIZE> B)
{
  
  for (unsigned i=0;i<SIZE;i++)  x[i]=x[i]-B[i];
  return *this;
}


template <class TYPE, unsigned SIZE>
Vector<TYPE,SIZE> Vector<TYPE,SIZE>::operator * ( const double mul)
{

  for (unsigned i=0;i<SIZE;i++)  x[i]=x[i]*mul;
  return *this;
}


template <class TYPE, unsigned SIZE>
TYPE Vector<TYPE,SIZE>::operator * ( const Vector<TYPE,SIZE> B)
{
  TYPE val;
  val=0;
  for (unsigned i=0;i<SIZE;i++)  val+=x[i]*B[i];
  return val;
}


template <class TYPE, unsigned SIZE>  
Vector<TYPE,SIZE> Vector<TYPE,SIZE>::operator / ( const double div)
{
  if(div==0)
    {
      std::cerr<<"dzielenie przez 0";
      exit(-1);
    }
  
  for (unsigned i=0;i<SIZE;i++)  x[i]=x[i]/div;
  return *this;
}


template <class TYPE, unsigned SIZE>
double Vector<TYPE,SIZE>::len()
{
  return sqrt(*this * *this);
}




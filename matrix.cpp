#include "matrix.hh"

template <class TYPE, unsigned SIZE>
std::ostream& operator << (std::ostream& str, const Matrix<TYPE,SIZE> &A)
{
  for (unsigned i=0; i<SIZE; i++) str<<A[i]<<'\n';
  return str;
}

template <class TYPE, unsigned SIZE>
std::istream& operator >> (std::istream &str, Matrix<TYPE,SIZE> &A)
{
  for(unsigned i=0; i<SIZE; i++) str>>A[i];
  return str;
}


template <class TYPE, unsigned SIZE>
TYPE Matrix<TYPE,SIZE>::det_lap()//wyznacznik laplace'a
{
  bool done[SIZE];//tablica na info o przerobionych kolumnach
  for (unsigned i=0; i<SIZE; i++)done[i]=false;//narazie zadna kolumna nie jest zrobiona
  
  return det_lap_part(done,0);
}

template <class TYPE, unsigned SIZE>
TYPE Matrix<TYPE,SIZE>::det_lap_part(bool done[SIZE], int rows)//indeksy przerobionych kolumn w tablicy
{
  TYPE result;
  result=0;
  if (SIZE==1) result=V[0][0];//dla macierzy 1x1
  else if(SIZE-rows==2)//dla macierzy 2x2
    {
      unsigned a[2], b=0;
      for(unsigned i=0; i<SIZE&&b<2; i++) if(!done[i]) a[b++]=i;//znajdz i zapisz indeksy nieprzerobionych kolumn
      result = V[a[0]][SIZE-2]*V[a[1]][SIZE-1] - V[a[1]][SIZE-2]*V[a[0]][SIZE-1];//policz wyzn. 2x2
    }
  else
    {
      double mul=1;
      for (unsigned i=0; i<SIZE; i++)
	{
	  if(done[i]);
	  else
	    {
	      done[i]=true;
	      result+= V[i][rows]*det_lap_part(done,rows+1)*mul;//kolejne rozwiniecia
	      mul*=-1;
	      done[i]=false;
	    }
	}
    }
  return result;
  
}


template <class TYPE, unsigned SIZE>
void Matrix<TYPE,SIZE>::transpose()
{
  for(unsigned i=0; i<SIZE; i++)
    {
      for(unsigned j=0; j<i; j++)
	{	  
	  std::swap(V[i][j],V[j][i]);
	}
    }
}

template <class TYPE, unsigned SIZE>
void Matrix<TYPE,SIZE>::colswap(int cnum, const Vector<TYPE,SIZE> &col)
{
  for(unsigned i=0; i<SIZE; i++)
    { 
      V[cnum][i]=col[i];
    }
}

template <class TYPE, unsigned SIZE>
Vector<TYPE,SIZE> Matrix<TYPE,SIZE>::operator * (const Vector<TYPE,SIZE> &X)
{
  Vector<TYPE,SIZE> result;
  for (unsigned i=0; i<SIZE; i++)
    {
      TYPE res;
      res=0;
      for (unsigned j=0; j<SIZE; j++)res+=V[j][i]*X[j];
      result[i]=res;
    }
  return result;
}

template <class TYPE, unsigned SIZE>
void Matrix<TYPE,SIZE>::operator = (const Matrix<TYPE,SIZE> &B)
{
  for (unsigned i=0; i<SIZE; i++)
    {
      for (unsigned j=0; j<SIZE; j++)
	{
	  V[i][j]=B[i][j];
	}
    }
}

template <class TYPE, unsigned SIZE>
Matrix<TYPE,SIZE> Matrix<TYPE,SIZE>::operator * (const Matrix<TYPE,SIZE> &X)
{
  Matrix<TYPE,SIZE> out;
  for (unsigned i=0; i<SIZE; i++)
    {
      out[i]=*this *X[i];
    }
  return out;
}

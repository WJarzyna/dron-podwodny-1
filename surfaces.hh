#include "matrix.hh"
#include "API/source/Dr3D_gnuplot_api.hh"

#define SURF_POINTS 5


using std::vector;
using drawNS::Point3D; 

/*
klasa powierzchni
pola: 
    wskaznik do api Draw3D
metody:
    draw - zwirtualizowana, rysuje powierzchnie (bug -rysuje lamane zamiast powierzchni)
 */

class surface
{
protected:
  std::shared_ptr<drawNS::Draw3DAPI> api;

public:
  virtual void draw()=0;
};


/*
klasa dna - plaska szara powierzchnia
pola:
   points - punkty na ktorych rozpiete jest dno
metody:
   konstruktor
      argumenty: wymiar (polowa realnej rozpietosci), glebokosc na jakiej ma byc dno, wskaznik do api Draw3D
 */

class bottom: public surface
{
  Vector<double,3> points[SURF_POINTS*SURF_POINTS];
  
public:
  bottom(float size,float height, std::shared_ptr<drawNS::Draw3DAPI> newapi);
  void draw();
};


/*
klasa wody - faldowana niebieska powierzchnia
pola:
   points - punkty na ktorych rozpiete jest dno
metody:
   konstruktor
      argumenty: wymiar (polowa realnej rozpietosci), wysokosc na jakiej ma byc powierzchnia, wskaznik do api Draw3D
 */


class water: public surface
{
  Vector<double,3> points[SURF_POINTS*SURF_POINTS];
  
public:
  water(float size,float height, std::shared_ptr<drawNS::Draw3DAPI> newapi);
  void draw();
};

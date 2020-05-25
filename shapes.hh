#include "matrix.hh"
#include "API/source/Dr3D_gnuplot_api.hh"

#define PI 3.14159265

using std::vector;
using drawNS::Point3D; 

/*
wieloscian
pola: api - wskaznik do api Draw3D
      id - id figury do modyfikacji
      angle_x,y,z - katy wzgledem globalnego ukladu
      pos - przesuniecie

metody:
   move_xyz - przesuniecie po osiach ukladu
   rot_x,y,z - obrot
   plot - rysowanie poprzez api
   rot_matrix:
      zwraca: macierz obrotu obliczona z katow
   erase - usuwa bryle
 */



class polyhedron
{
protected:
  std::shared_ptr<drawNS::Draw3DAPI> api;
  int id;
  double angle_z,angle_x,angle_y; //katy w radianach
  Vector<double,3> pos;//pozycja srodka w ukladzie
  //Matrix<double,3> rot_matrix;
public:
  void move_xyz(Vector<double,3> shift){pos+=shift;};//przesuniecie po osiach
  void rot_z(double angle) {angle_z+=angle;};//obroty
  void rot_x(double angle) {angle_x+=angle;};
  void rot_y(double angle) {angle_y+=angle;};
  virtual void plot()=0;
  Matrix<double,3> rot_matrix();
  void erase(){api->erase_shape(id);};
};

/*
klasa prostopadloscian
pola:
    apex - wierzcholki

metody:
    konstruktor:
       argumenty: wymiary x,y,z, wskaznik do api Draw3D
 */

class cuboid: public polyhedron
{
protected:
  Vector<double,3> apex[8];
public:
  explicit cuboid(double x, double y, double z, std::shared_ptr<drawNS::Draw3DAPI> newapi);//konstruktor po wymiarach
  void plot();
};

/*
klasa graniastoslup szesciokatny
pola:
    apex - wierzcholki

metody:
    konstruktor:
       argumenty: wysokosc, promien podstawy, wskaznik do api Draw3D
 */

class hex_prism: public polyhedron
{
protected:
  Vector<double,3> apex[12];
public:
  explicit hex_prism(double h, double r, std::shared_ptr<drawNS::Draw3DAPI> newapi);//konstruktor po wymiarach
  void plot();
};

#include "matrix.hh"
#include "API/source/Dr3D_gnuplot_api.hh"

#define PI 3.14159265

using std::vector;
using drawNS::Point3D; 

class polyhedron
{
protected:
  double angle_z,angle_x,angle_y; //katy w radianach
  Vector<double,3> pos;//pozycja srodka w ukladzie
public:
  void move_xyz(Vector<double,3> shift){pos+=shift;};//przesuniecie po osiach
  void rot_z(double angle) {angle_z+=angle;};//obroty
  void rot_x(double angle) {angle_x+=angle;};
  void rot_y(double angle) {angle_y+=angle;};
  Matrix<double,3> rot_matrix ();//macierz obrotu sumaryczna
};

class cuboid: public polyhedron
{
protected:
  Vector<double,3> apex[8];
public:
  explicit cuboid(double x, double y, double z);//konstruktor po wymiarach
  void move(Vector<double,3> shift);
  vector<vector<Point3D>> plot();//zwraca dane do API
};

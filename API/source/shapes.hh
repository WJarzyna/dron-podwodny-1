#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D; 

class cuboid
{
  vector<vector<Point3D> > apex=vector<vector<Point3D> > {{
      Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0)},{
      Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0)}};
  vector<double> pos=vector<double>{0,0,0};
  
public:
  explicit cuboid(double x, double y, double z);
  vector<vector<Point3D> > get() {return apex;};
  void move(Point3D shift);
};

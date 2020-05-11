#include "shapes.hh"


cuboid::cuboid(double x, double y, double z)
{
  apex=vector<vector<Point3D> > {{
      Point3D(x/2,y/2,z/2),Point3D(x/2,-y/2,z/2),Point3D(-x/2,-y/2,z/2),Point3D(-x/2,y/2,z/2)},{
      Point3D(x/2,y/2,-z/2),Point3D(x/2,-y/2,-z/2),Point3D(-x/2,-y/2,-z/2),Point3D(-x/2,y/2,-z/2)}};
}

void cuboid::move(Point3D shift)
{
  for(unsigned i=0; i<3; ++i)
    {
      for(unsigned j=0; j<8; ++j)apex[j/2][j%4][i]+=shift[i];
    }
}
	    

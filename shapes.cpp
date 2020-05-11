#include "shapes.hh"

cuboid::cuboid(double x, double y, double z)
{
  Vector<double,3> vect;
  vect[0]=-x/2;
  vect[1]=-y/2;
  vect[2]=-z/2;
  for(unsigned i=0; i<8; ++i)
    {
      if(!((i+1)%2))vect[0]=-vect[0];
      if(!(i%2))vect[1]=-vect[1];
      if(!(i%4))vect[2]=-vect[2];
      apex[i]=vect;
    }
}



vector<vector<Point3D>> cuboid::plot()
{
  vector<vector<Point3D> > apex_to_plot=vector<vector<Point3D> > {{
      Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0)},{
      Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0)}};
  for(unsigned i=0; i<8; i++)
    {
      Vector<double,3> out;
      out=rot_matrix()*apex[i]+pos;
      for(unsigned j=0; j<3; j++)
	{
	   apex_to_plot[i/4][i%4][j]=out[j];
	}
    }
  return apex_to_plot;
}



Matrix<double,3> polyhedron::rot_matrix()
{
  Matrix<double,3> rot_z, rot_y, rot_x;
  rot_z[0][0]=cos(angle_z);
  rot_z[0][1]=sin(angle_z);
  rot_z[1][0]=-sin(angle_z);
  rot_z[1][1]=cos(angle_z);
  rot_z[2][2]=1;
  rot_y[0][0]=cos(angle_y);
  rot_y[2][0]=sin(angle_y);
  rot_y[0][2]=-sin(angle_y);
  rot_y[2][2]=cos(angle_y);
  rot_y[1][1]=1;
  rot_x[1][1]=cos(angle_x);
  rot_x[1][2]=sin(angle_x);
  rot_x[2][1]=-sin(angle_x);
  rot_x[2][2]=cos(angle_x);
  rot_x[0][0]=1;
  return rot_x*rot_y*rot_z;
}


void cuboid::move(Vector<double,3> shift)
{
  move_xyz(rot_matrix()*shift);
}

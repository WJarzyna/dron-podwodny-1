#include "shapes.hh"

bool polyhedron::is_colliding(polyhedron &obj)
{
  Vector<double,3> dist_v;
  
  dist_v=pos;
  dist_v=dist_v - obj.get_pos();
  return dist_v.len()<(this->get_col_radius()+obj.get_col_radius());
}


cuboid::cuboid(double x, double y, double z, std::shared_ptr<drawNS::Draw3DAPI> newapi)
{
  ++count;
  api=newapi;
  //rot_matrix[0][0]=rot_matrix[1][1]=rot_matrix[2][2]=1;
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



void cuboid::plot()
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
  id=api->draw_polyhedron( apex_to_plot,"black");
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

/*
void polyhedron::rot_z(double angle)
{
  Matrix<double,3> rot_z;
  rot_z[0][0]=cos(angle_z);
  rot_z[0][1]=sin(angle_z);
  rot_z[1][0]=-sin(angle_z);
  rot_z[1][1]=cos(angle_z);
  rot_z[2][2]=1;
  rot_matrix=rot_matrix*rot_z;
}

void cuboid::move(Vector<double,3> shift)
{
  move_xyz(rot_matrix*shift);
}
*/

hex_prism::hex_prism(double h, double r,std::shared_ptr<drawNS::Draw3DAPI> newapi)
{
  ++count;
  api=newapi;

  //rot_matrix[0][0]=rot_matrix[1][1]=rot_matrix[2][2]=1;
  apex[0][0]=r;
  apex[0][2]=h/2;

  apex[1][0]=r/2;
  apex[1][1]=r*0.865;
  apex[1][2]=h/2;

  apex[2][0]=-r/2;
  apex[2][1]=r*0.865;
  apex[2][2]=h/2;

   apex[3][0]=-r;
  apex[3][2]=h/2;

  apex[4][0]=-r/2;
  apex[4][1]=-r*0.865;
  apex[4][2]=h/2;

  apex[5][0]=r/2;
  apex[5][1]=-r*0.865;
  apex[5][2]=h/2;

   apex[6][0]=r;
  apex[6][2]=-h/2;

  apex[7][0]=r/2;
  apex[7][1]=r*0.865;
  apex[7][2]=-h/2;

  apex[8][0]=-r/2;
  apex[8][1]=r*0.865;
  apex[8][2]=-h/2;

  apex[9][0]=-r;
  apex[9][2]=-h/2;

  apex[10][0]=-r/2;
  apex[10][1]=-r*0.865;
  apex[10][2]=-h/2;

  apex[11][0]=r/2;
  apex[11][1]=-r*0.865;
  apex[11][2]=-h/2;
}

void hex_prism::plot()
{
  vector<vector<Point3D> > apex_to_plot=vector<vector<Point3D> > {{
      Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0)},{
      Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0),Point3D(0,0,0)}};
  
  for(unsigned i=0; i<12; i++)
    {
      Vector<double,3> out;
      out=rot_matrix()*apex[i]+pos;

      for(unsigned j=0; j<3; j++)
	{
	   apex_to_plot[i/6][i%6][j]=out[j];
	}
    }
  id=api->draw_polyhedron(apex_to_plot,"red");
}

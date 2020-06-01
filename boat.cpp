#include "boat.hh"





void boat::move(Vector<double,3> shift)
{
  Vector<double,3> step=rot_matrix()*shift/10;
  Vector<double,3> zero;
  for(int fcnt=0; fcnt<10; ++fcnt)
    {
      //rscrew.move_xyz(zero);
      move_xyz(step);
      lscrew.rot_x(PI/12);
      //lscrew.move_xyz(zero);
      //lscrew.move_xyz(pos+rot_matrix()*ref[0]);
      lscrew.move_xyz(step);
      lscrew.erase();
      lscrew.plot();
      rscrew.rot_x(PI/12);
      
      //rscrew.move_xyz(pos+rot_matrix()*ref[0]);
      rscrew.move_xyz(step);
      rscrew.erase();
      rscrew.plot();
      erase();
      plot();
    }
}
/*
bool boat::is_colliding(polyhedron &obj)
{
  Vector<double,3> dist_v;
  dist_v=pos - obj->get_pos();
  return dist_v.len()<(this->get_col_radius()+obj.get_col_radius());
}
*/


void interface::rotate(boat* boat, char axis, double angle)
{
  angle=angle*2*PI/360;
  switch(axis)
    {
    case 'x':;
    case 'X':boat->rot_x(angle);break;
    case 'y':;
    case 'Y':boat->rot_y(angle);break;
    case 'z':;
    case 'Z':boat->rot_z(angle);break;
    default:std::cerr<<"zla os"<<'\n';
    }
}

#include "boat.hh"

void boat::move(Vector<double,3> shift)
{
  move_xyz(rot_matrix()*shift);
}

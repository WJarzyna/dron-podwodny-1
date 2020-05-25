#include "boat.hh"





void boat::move(Vector<double,3> shift)
{
  Vector<double,3> step=rot_matrix()*shift/10;
  for(int fcnt=0; fcnt<10; ++fcnt)
    {
      move_xyz(step);
      lscrew.rot_x(PI/12);
      lscrew.move_xyz(step);
      lscrew.erase();
      lscrew.plot();
      erase();
      plot();
    }
}




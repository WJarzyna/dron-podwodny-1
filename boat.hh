#include "shapes.hh"

/**
\brief klasa drona

konstruktor:
    argument: wskaznik do api

    tworzy drona z dwoma wirnikami, ustawia wirniki w polozeniu startowym

move:
    porusza dronem zgodnie z jego orentacja

    argument: wektor przemieszczenia
 */


class boat:public cuboid
{
  hex_prism lscrew;
  hex_prism rscrew;
public:
  boat(std::shared_ptr<drawNS::Draw3DAPI> newapi): cuboid(5,3,3,newapi),  lscrew(2,1,newapi), rscrew(2,1,newapi)
  {
    Vector<double,3> ref;
    ref[0]=-3.5;
    ref[1]=1.5;
    lscrew.move_xyz(ref);
    ref[1]=-1.5;
    rscrew.move_xyz(ref);
    rscrew.rot_y(PI/2);
    lscrew.rot_y(PI/2);
    rscrew.plot();
    lscrew.plot();
  };
  
  void move(Vector<double,3> shift);
};

#include "shapes.hh"

/**
\brief klasa drona
 */


class boat:public cuboid
{
  hex_prism lscrew;
  hex_prism rscrew;
  Vector<double,3> ref[2];
public:
  boat(std::shared_ptr<drawNS::Draw3DAPI> newapi): cuboid(5,3,3,newapi),  lscrew(2,1,newapi), rscrew(2,1,newapi)
  {
    ref[0][0]=ref[1][0]=-3.5;
    ref[0][1]=1.5;
    ref[1][1]=-1.5;
    lscrew.move_xyz(ref[0]);
    rscrew.move_xyz(ref[1]);
    rscrew.rot_y(PI/2);
    lscrew.rot_y(PI/2);
    rscrew.plot();
    lscrew.plot();
  };/**<argument: wskaznik do api, tworzy drona z dwoma wirnikami, ustawia wirniki w polozeniu startowym */
  
  void move(Vector<double,3> shift); /**< porusza dronem zgodnie z jego orentacja. argument: wektor przemieszczenia */
 
};

class interface
{
public:
  void move(boat* boat, Vector<double,3> mov){boat->move(mov);};
  void rotate(boat* boat, char axis, double angle);
  void plot(boat* boat){boat->plot();};
};

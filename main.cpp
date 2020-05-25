#include "boat.hh"
#include "surfaces.hh"
using drawNS::APIGnuPlot3D;

#define SCN_SIZE 10
#define SCN_DEPTH -10
#define WAT_H 9

int main()
{
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-SCN_SIZE,SCN_SIZE,-SCN_SIZE,SCN_SIZE,SCN_DEPTH,-SCN_DEPTH,0));//inicjalizacja gnuplota

  bottom sand(SCN_SIZE,SCN_DEPTH,api);
  water top(SCN_SIZE,WAT_H,api);
  
  sand.draw();
  top.draw();

  boat boat(api);
  boat.plot();

  bool ctrl_flag=false;
  while(!ctrl_flag)
    {
      Vector<double,3> m;
      switch(std::cin.get())
	{
	case 'w':m[0]=1;break;
	case 's':m[0]=-1;break;
	case 'a':boat.rot_z(-PI/12);break;
	case 'd':boat.rot_z(PI/12);break;
	case 'r':boat.rot_x(-PI/36);break;
	case 'f':boat.rot_x(PI/36);break;
	case 'q':ctrl_flag=true;break;
	}
      boat.move(m);
      api ->redraw();
    }
  
}

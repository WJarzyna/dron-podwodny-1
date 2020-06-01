#include "boat.hh"
#include "surfaces.hh"
using drawNS::APIGnuPlot3D;
using std::cout;

#define SCN_SIZE 20
#define SCN_DEPTH -10
#define WAT_H 9

int main()
{
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-SCN_SIZE,SCN_SIZE,-SCN_SIZE,SCN_SIZE,SCN_DEPTH,-SCN_DEPTH,0));//inicjalizacja gnuplota

  bottom sand(SCN_SIZE,SCN_DEPTH,api);
  water top(SCN_SIZE,WAT_H,api);
  
  sand.draw();
  top.draw();

  std::vector<hex_prism*> obj;
  obj.push_back(new hex_prism(2,2,api));
  obj.push_back(new hex_prism(6,1,api));
  obj.push_back(new hex_prism(6,2,api));

  Vector<double,3> objpos;
  objpos[0]=8;
  objpos[1]=8;
  obj[0]->move_xyz(objpos);
  objpos[0]=-8;
  objpos[1]=-8;
  obj[1]->move_xyz(objpos);
  objpos[0]=2;
  objpos[1]=-15;
  objpos[2]=-5;
  obj[2]->move_xyz(objpos);

  for(hex_prism* x:obj)
    {
      x->plot();
    }

  
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
      //if(boat.is_colliding(duck))cout<<"kolizja!";
    }
  
}

#include "shapes.hh"
using drawNS::APIGnuPlot3D;


int main()
{
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,0));//inicjalizacja gnuplota
  cuboid cube(4,4,4);
  Vector<double,3> V;
  V[0]=V[1]=V[2]=-8;
  cube.move_xyz(V);
  api->draw_polyhedron(cube.plot());//znika po narysowaniu lodki
  

  
  cuboid boat(5,2,2);
  int cubeid=api->draw_polyhedron(boat.plot());

  int ctrl_flag=0;
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
	case 'q':ctrl_flag=1;break;
	}
      boat.move(m);
      api -> erase_shape(cubeid);
      cubeid=api->draw_polyhedron(boat.plot());
      api ->redraw();
    }
  for (unsigned x=0; x<255; ++x)
    {
      boat.rot_z(PI/12);
      api -> erase_shape(cubeid);
      cubeid=api->draw_polyhedron(boat.plot());
      api ->redraw();
    }
}

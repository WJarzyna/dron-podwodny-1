#include "boat.hh"
#include "surfaces.hh"
using drawNS::APIGnuPlot3D;
using std::cout;

#define SCN_SIZE 20
#define SCN_DEPTH -10
#define WAT_H 9

#define HELP " e -zmiana drona \n w,s - jazda przod-tyl \n a,d - skret po OZ \n r,f - skret po OX \n p - pokaz dane \n q - wyjscie"


int main()
{
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-SCN_SIZE,SCN_SIZE,-SCN_SIZE,SCN_SIZE,SCN_DEPTH,-SCN_DEPTH,0));//inicjalizacja gnuplota

  bottom sand(SCN_SIZE,SCN_DEPTH,api);
  water top(SCN_SIZE,WAT_H,api);
  
  sand.draw();
  top.draw();

  std::vector<polyhedron*> obj;
  obj.push_back(new hex_prism(2,2,api));
  obj.push_back(new cuboid(6,1,2,api));
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

  for(polyhedron* x:obj)
    {
      x->plot();
    }

  std::vector<boat*> b;
  
  b.push_back(new boat(api));
  b.push_back(new boat(api));

  interface in;
  in.plot(b[0]);
  in.plot(b[1]);

  cout<<HELP<<'\n';
  bool ctrl_flag=false;
  int drno=0;
  while(!ctrl_flag)
    {
      
      Vector<double,3> m;
      switch(std::cin.get())
	{
	case 'e':drno=drno?0:1;break;
	case 'w':m[0]=1;break;
	case 's':m[0]=-1;break;
	case 'a':in.rotate(b[drno],'z',10);break;
	case 'd':in.rotate(b[drno],'z',-10);break;
	case 'r':in.rotate(b[drno],'x',30);break;
	case 'f':in.rotate(b[drno],'x',-30);break;
	case 'p':cout<<"stworzono "<<polyhedron::poly_cnt()<<"wieloscianow "<<Vector<double,3>::vect_cnt()<<" wektorow"<<'\n';break;
	case 'q':ctrl_flag=true;break;
	}
      in.move(b[drno],m);
      for(polyhedron* x:obj)
	  {
	    if(b[drno]->is_colliding(*x))cout<<"kolizja\n";
	  }
      api ->redraw();
    }
  
}

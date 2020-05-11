#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "shapes.hh"


using std::vector;
using drawNS::Point3D; 
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

int main()
{
   std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000));

   cuboid cube(2,3,4);
   while(std::cin.get() != '\n');

   
   api->draw_polyhedron(cube.get());
   while(std::cin.get() != '\n');
   
   while(1)
     {
       while(std::cin.get() != '\n');
       cube.move(Point3D(1,0,0));
     }
}

#include "surfaces.hh"


bottom::bottom(float size, float height, std::shared_ptr<drawNS::Draw3DAPI> newapi)
{
  api=newapi;
  
  Vector<double,3> point;
  point[2]=height;
  
  for(unsigned i=0; i<SURF_POINTS; ++i)
    {
      point[0]=-size+i*size/2;

      for(unsigned j=0; j<SURF_POINTS; ++j)
	{
	  point[1]=-size+j*size/2;
	  points[SURF_POINTS*i+j]=point;
	  
	}
    }
}

void bottom::draw()
{
  vector<vector<Point3D> > points_to_plot;
  vector<Point3D> add;
  
  for(unsigned i=0; i<SURF_POINTS; i++)
    {
      for(unsigned j=0; j<SURF_POINTS; j++)
	{
	  add.push_back(Point3D(points[SURF_POINTS*i+j][0],points[SURF_POINTS*i+j][1],points[SURF_POINTS*i+j][2]));
	}
      points_to_plot.push_back(add);
    }
  api->draw_surface(points_to_plot, "grey");
}

water::water (float size, float height, std::shared_ptr<drawNS::Draw3DAPI> newapi)
{
  api=newapi;
  
  Vector<double,3> point;
  point[2]=height;

  float mov=1;
  
  for(unsigned i=0; i<SURF_POINTS; ++i)
    {
      
      point[1]=-size+i*size/2;
      point[2]+=mov;
      mov*=-1;
      
      for(unsigned j=0; j<SURF_POINTS; ++j)
	{
	  point[0]=-size+j*size/2;
	  points[SURF_POINTS*i+j]=point;
	  
	}
    }
}


void water::draw()
{
  vector<vector<Point3D> > points_to_plot;
  vector<Point3D> add;
  
  for(unsigned i=0; i<SURF_POINTS; i++)
    {
      for(unsigned j=0; j<SURF_POINTS; j++)
	{
	  add.push_back(Point3D(points[SURF_POINTS*j+i][0],points[SURF_POINTS*j+i][1],points[SURF_POINTS*j+i][2]));
	}
      points_to_plot.push_back(add);
    }
  api->draw_surface(points_to_plot, "blue");
}

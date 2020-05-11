#include "shapes.hh"

class boat:public cuboid
{
  cuboid body;
public:
  void move(Vector<double,3> shift);
};

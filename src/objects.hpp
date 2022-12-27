#ifndef OBJECTS
#define OBJECTS

#include <vector>
#include "shape.hpp"
#include "ray.hpp"

class objects {
  public:
    objects();
    shape* shapeAt(int index);
    void append(shape* shape);
    float closestIntersection(ray r);
    shape* getClosest();
  
  private:
    std::vector<shape*> shapes;
    int closestIndex;
};

#endif
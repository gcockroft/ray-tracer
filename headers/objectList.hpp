#ifndef OBJECTLIST
#define OBJECTLIST

#include <vector>
#include "object.hpp"
#include "ray.hpp"

class objectList {
  public:
    objectList();
    object* objectAt(int index);
    void append(object* object);
    float closestIntersection(ray r);
    object* getClosest();
  
  private:
    std::vector<object*> objectVec;
    int closestIndex;
};

#endif
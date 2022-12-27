#ifndef OBJECT
#define OBJECT

#include "ray.hpp"

class object {
  public:
    object() = default;
    virtual float test_intersection(ray r) = 0;
    virtual ~object() = default;
  protected:
    int matIndex;
};

#endif
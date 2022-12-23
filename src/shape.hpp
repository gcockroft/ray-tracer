#ifndef SHAPE
#define SHAPE

#include "ray.hpp"

class shape {
  public: 
    shape() = default;
    virtual float test_intersection(ray r) = 0;
    virtual ~shape() = default;
};

#endif
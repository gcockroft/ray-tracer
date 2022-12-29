#ifndef OBJECT
#define OBJECT

#include "ray.hpp"

class object {
  public:
    object() = default;
    virtual float test_intersection(ray r) = 0;
    virtual vec3 getNormal(vec3 point) = 0;
    virtual ~object() = default;
    int getMatIndex() {
      return matIndex;
    }
  protected:
    int matIndex;
};

#endif
#ifndef TRI
#define TRI
#include <cmath>

#include "vec3.hpp"
#include "ray.hpp"
#include "shape.hpp"

class triangle : public shape {
  public:
    vec3 p1;
    vec3 p2;
    vec3 p3;

    triangle(vec3 _a, vec3 _b, vec3 _c);

    // Returns distance to triangle or NaN for no intersection.
    float test_intersection(ray r);
};

#endif
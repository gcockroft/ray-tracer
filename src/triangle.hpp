#ifndef TRI
#define TRI
#include <cmath>

#include "vec3.hpp"
#include "ray.hpp"
#include "object.hpp"

class triangle : public object {
  public:
    vec3 p1;
    vec3 p2;
    vec3 p3;
    vec3 t0;
    vec3 t1;
    vec3 t2;

    triangle(vec3 _a, vec3 _b, vec3 _c, int _matIndex);
    triangle(vec3 _a, vec3 _b, vec3 _c, vec3 _t0, vec3 _t1, vec3 _t2, int _matIndex);

    // Returns distance to triangle or NaN for no intersection.
    float test_intersection(ray r);
    vec3 getNormal(vec3 point);
    vec3 getTextureCoordinates(ray r);
};

#endif
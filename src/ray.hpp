#ifndef RAY
#define RAY
#include "vec.hpp"

class ray {
  public:
    vec3 origin;
    vec3 direction;
  
    ray(vec3 orig, vec3 dir) {
      origin = orig;
      direction = dir;
    }

    vec3 origin(ray r) const {
      return origin;
    }

    vec3 direction(ray r) const {
      return direction;
    }

    vec3 at(double t) const {
      return origin + t*direction;
    }
};

#endif
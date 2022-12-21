#ifndef RAY
#define RAY

#include "vec3.hpp"

class ray {
  public:
    vec3 origin;
    vec3 direction;

    ray() {
      origin = vec3();
      direction = vec3();
    }
  
    ray(vec3 orig, vec3 dir) {
      origin = orig;
      direction = dir;
    }

    vec3 getOrigin(ray r) const {
      return origin;
    }

    vec3 getDirection(ray r) const {
      return direction;
    }

    vec3 at(double t) const {
      return origin + t*direction;
    }
};

#endif
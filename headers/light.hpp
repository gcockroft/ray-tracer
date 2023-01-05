#ifndef LIGHT
#define LIGHT

#include "vec3.hpp"

class light {
  public:
    vec3 location;
    vec3 color;

    light();
    light(vec3 l, vec3 c) {
      location = l;
      color = c;
    }
};

#endif
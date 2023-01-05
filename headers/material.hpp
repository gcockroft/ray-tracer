#ifndef MATERIAL
#define MATERIAL

#include "vec3.hpp"

class material {
  public:
    vec3 diffuseCol, specularCol, transparentCol, reflectiveCol;
    float shininess, refractionIndex;

    material();
    material(vec3 dC, vec3 sC, vec3 tC, vec3 rC, float shine, float ref) {
      diffuseCol = dC;
      specularCol = sC;
      transparentCol = tC;
      reflectiveCol = rC;
      shininess = shine;
      refractionIndex = ref;
    }
};

#endif
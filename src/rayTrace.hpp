#ifndef RAYTRACE
#define RAYTRACE

#include "vec3.hpp"
#include "objectList.hpp"
#include "ray.hpp"
#include "triangle.hpp"
#include "light.hpp"
#include "scene.hpp"
#include <vector>

using namespace std;

#define backgroundColor vec3(0.55f, 0.5f, 0.8f)
vec3 rayTrace(ray r, scene *myScene, int recurseDepth);
vec3 refract(vec3 r_i, vec3 normal, float index);
#endif
#ifndef RAYTRACE
#define RAYTRACE

#include "vec3.hpp"
#include "objects.hpp"
#include "ray.hpp"
#include "triangle.hpp"
#include "light.hpp"
#include <vector>

#define backgroundColor vec3(0.55f, 0.5f, 0.8f)
vec3 rayTrace(ray r, std::vector<shape*> shapes);

#endif
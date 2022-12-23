#ifndef SPHERE
#define SPHERE

#include "shape.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class sphere : public shape {
public: 
	float center;
	float radius;

	sphere(float c, float r);

	float test_intersection(ray r);
};

#endif
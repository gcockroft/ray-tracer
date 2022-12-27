#ifndef SPHERE
#define SPHERE

#include "shape.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class sphere : public shape {
	public: 
		vec3 center;
		float radius;

		sphere(vec3 c, float r);

		float test_intersection(ray r);
};

#endif
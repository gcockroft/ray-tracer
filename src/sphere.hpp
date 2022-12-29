#ifndef SPHERE
#define SPHERE

#include "object.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class sphere : public object {
	public: 
		vec3 center;
		float radius;

		sphere(vec3 c, float r, int _matIndex);

		float test_intersection(ray r);

		vec3 getNormal(vec3 point);
};

#endif
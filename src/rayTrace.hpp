#ifndef RAYTRACE
#define RAYTRACE

#include "vec3.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "triangle.hpp"
#include <vector>

#define backgroundColor vec3(141.0f, 120.0f, 200.0f)

vec3 rayTrace(ray r, std::vector<shape*> shapes) {

    //test intersections
    float minT = 99999999;
    float t = NAN;
    for (int i = 0; i < shapes.size(); i++) {
        
        t = shapes.at(i)->test_intersection(r);
        if (t < minT) {
            minT = t;
        }
    }
    if (!isnan(t)) {
        std::cout << t << std::endl;
    }

    if (minT != 99999999) {
        return vec3(200,0,0);
    }

    //if touches nothing 
    if (t == t) {
        return vec3(200,0,0);
    }
    return backgroundColor;

}

#endif
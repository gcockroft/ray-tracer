#ifndef RAYTRACE
#define RAYTRACE

#include "vec3.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "triangle.hpp"

#define backgroundColor vec3(141.0f, 120.0f, 200.0f)

vec3 rayTrace(ray r, std::vector<Triangle> shapes) {

    //test intersections
    float minT = 99999999;
    float t = shapes[0].test_intersection(r);
    // for (Triangle shape: shapes) {
    //     float t = shape.test_intersection(r);
    //     std::cout << t<< std::endl;
    // }
    //     if (t < minT) {
    //         minT = t;
    //         std::cout << "bitch" << std::endl;
    //     }
    // }

    // if(minT != 99999999) {
    //     return vec3(200,0,0);
    // }

    //if touches nothing 
    if (t == t) {
        return vec3(200,0,0);
    }
    return backgroundColor;

}

#endif
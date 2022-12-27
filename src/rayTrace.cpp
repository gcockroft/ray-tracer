#include "rayTrace.hpp"

vec3 rayTrace(ray r, std::vector<shape*> shapes) {

    //test intersections
    float t = closestIntersection(r, shapes);

    if (isnan(t)) 
        return backgroundColor;
    
    
    if (!isnan(t)) {
        std::cout << t << std::endl;
        return vec3(0.7f,0,0);
    }

    return backgroundColor;

}

float closestIntersection(ray r, std::vector<shape*> shapes) {
    
    float minT = 99999999;
    float t = NAN;
    for (int i = 0; i < shapes.size(); i++) {
        
        t = shapes.at(i)->test_intersection(r);
        if (t < minT) {
            minT = t;
        }
    }

    if (minT != 99999999) {
        return minT;
    } else {
        return NAN;
    }
}
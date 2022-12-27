#include "rayTrace.hpp"

vec3 rayTrace(ray r, scene *myScene) {
    objectList *objs = myScene->objs;
    vector<material> mats = myScene->materials;
    vector<light> lights = myScene->lights;

    //test intersections
    float t = objs->closestIntersection(r);
    
    if (!isnan(t)) {
        std::cout << t << std::endl;
        return vec3(0.7f,0,0);
    }

    return backgroundColor;
}

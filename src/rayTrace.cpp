#include "rayTrace.hpp"

vec3 rayTrace(ray r, scene *myScene, int recurseDepth) {
    objectList *objs = myScene->objs;
    vector<material> mats = myScene->materials;
    vector<light> lights = myScene->lights;

    //test intersections
    float t = objs->closestIntersection(r);
    if (isnan(t)) {
        return backgroundColor;
    }

    object* object = objs->getClosest();
    material mat = mats.at(object->getMatIndex());
    vec3 point = r.at(t);
    vec3 res = vec3(0,0,0);

    vec3 diffuseColor = mat.diffuseCol;
    res = res + diffuseColor * myScene->ambientLight;

    return res;
}

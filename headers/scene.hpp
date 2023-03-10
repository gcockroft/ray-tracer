#ifndef SCENE
#define SCENE

#include <vector>
#include "camera.hpp"
#include "light.hpp"
#include "material.hpp"
#include "objectList.hpp"

using namespace std;

class scene {
    public:
        scene() {};
        vector<light> lights;
        vector<material> materials;
        objectList *objs;
        vec3 ambientLight;
        vec3 backgroundColor;
        camera cam;
};

#endif
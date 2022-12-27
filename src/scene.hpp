#ifndef SCENE
#define SCENE

#include <vector>
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
};

#endif
#ifndef INIT
#define INIT

#include "vec3.hpp"
#include "triangle.hpp"
#include "sphere.hpp"
#include "objectList.hpp"
#include "light.hpp"
#include "material.hpp"
#include "scene.hpp"

using namespace std;

scene* initScene();
objectList* initObjectList();
vector<light> initLights();
vector<material> initMaterials();
vec3 getCamera();


#endif
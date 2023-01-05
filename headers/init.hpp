#ifndef INIT
#define INIT

#include "vec3.hpp"
#include "camera.hpp"
#include "triangle.hpp"
#include "sphere.hpp"
#include "objectList.hpp"
#include "light.hpp"
#include "material.hpp"
#include "scene.hpp"

using namespace std;

scene* initScene(int image_height, int image_width);
camera initCamera(int image_height, int image_width);
objectList* initObjectList();
vector<light> initLights();
vector<material> initMaterials();


#endif
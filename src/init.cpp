#include "init.hpp"

scene* initScene(vec3 camEye) {
    scene* myScene = new scene(camEye);
    myScene->materials = initMaterials();
    myScene->lights = initLights();
    myScene->objs = initObjectList();
    myScene->ambientLight = vec3(1,1,1);

    return myScene;
}

vector<material> initMaterials() {
    vector<material> materials;

    float shininess = 50;
    float refractionIndex = 1;
    vec3 diffuseCol = vec3(0.7, 0.3, 0.2);
    vec3 specularCol = vec3(0.4,0.4,0.4);
    vec3 transparantCol = vec3(0.8,0.8,0.8);
    vec3 reflectiveCol = vec3(0.5,0.5,0.5);

    float shininess1 = 50;
    float refractionIndex1 = 1;
    vec3 diffuseCol1 = vec3(0.3, 0.3, 0.3);
    vec3 specularCol1 = vec3(0.3,0.3,0.3);
    vec3 transparantCol1 = vec3(0,0,0);
    vec3 reflectiveCol1 = vec3(0.3,0.3,0.3);

    material m1 = material(diffuseCol,specularCol,transparantCol, reflectiveCol, shininess, refractionIndex);
    material m2 = material(diffuseCol1, specularCol1, transparantCol1, reflectiveCol1, shininess1, refractionIndex1);
    materials.push_back(m1);
    materials.push_back(m2);
    return materials;
}

vector<light> initLights() {
    vector<light> lights;

    vec3 position = vec3(-5.0f, 5.0f, 5.0f);
    vec3 color = vec3(1,1,1);
    light l1 = light(position, color);
    lights.push_back(l1);

    return lights;
}

objectList* initObjectList() {
    objectList *list = new objectList();

    vec3 a = vec3(0,2,-3);
    vec3 b = vec3(0,-2,-3);
    vec3 c = vec3(3,-2,0);

    vec3 a1 = vec3(0,2,-3);
    vec3 a2 = vec3(3,-2,0);
    vec3 a3 = vec3(3,2,0);

    vec3 cent = vec3(0,0,0);
    float rad = 0.5f;

    triangle *t = new triangle(a,b,c, 1);
    triangle *t1 = new triangle(a1,a2,a3, 1);
    sphere *s = new sphere(cent, rad, 0);
    
    list->append(t);
    list->append(t1);
    list->append(s);

    return list;
}
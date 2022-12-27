#include "init.hpp"

scene* initScene() {
    scene* myScene = new scene();
    myScene->materials = initMaterials();
    myScene->lights = initLights();
    myScene->objs = initObjectList();

    return myScene;
}

vector<material> initMaterials() {
    vector<material> materials;

    float shininess = 50;
    float refractionIndex = 1;
    vec3 diffuseCol = vec3(0.7, 0.3, 0.2);
    vec3 specularCol = vec3(1,1,1);
    vec3 transparantCol = vec3(0.8,0.8,0.8);
    vec3 reflectiveCol = vec3(0.5,0.5,0.5);

    material m1 = material(diffuseCol,specularCol,transparantCol, reflectiveCol, shininess, refractionIndex);
    materials.push_back(m1);
    return materials;
}

vector<light> initLights() {
    vector<light> lights;

    vec3 position = vec3(5.0f, 5.0f, 5.0f);
    vec3 color = vec3(1,1,1);
    light l1 = light(position, color);
    lights.push_back(l1);

    return lights;
}

objectList* initObjectList() {
    objectList *list = new objectList();

    vec3 a = vec3(-2,2,0.0f);
    vec3 b = vec3(-2,1,0.0f);
    vec3 c = vec3(-1,2,0.0f);

    vec3 a1 = vec3(2,-1,0.0f);
    vec3 a2 = vec3(2,-2,0.0f);
    vec3 a3 = vec3(1,-2,0.0f);

    vec3 cent = vec3(0,0,0);
    float rad = 1.0f;

    triangle *t = new triangle(a,b,c, 0);
    triangle *t1 = new triangle(a1,a2,a3, 0);
    sphere *s = new sphere(cent, rad, 0);
    
    list->append(t);
    list->append(t1);
    list->append(s);

    std::cout << t->p1 << std::endl;

    return list;
}
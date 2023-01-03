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

    vec3 diffuse = vec3(0.2f, 0.7f, 0.2f);
    vec3 specular = vec3(0.2f, 0.7f, 0.2f);
    vec3 reflective = vec3();
    float shininess = 50;
    vec3 transparent = vec3();
    float ior = 0.6f;

    material mat1 = material(diffuse, specular, transparent, reflective, shininess, ior);

    diffuse = vec3(0.1f,0.1f,0.1f);
    specular = vec3(0.1f,0.1f,0.1f);
    reflective = vec3(0.1f,0.1f,0.1f);
    shininess = 50;
    transparent = vec3(0.9f,0.9f,0.9f);
    ior = 1.5f;

    material mat2 = material(diffuse, specular, transparent, reflective, shininess, ior);    

    materials.push_back(mat1);
    materials.push_back(mat2);
    
    return materials;
}

vector<light> initLights() {
    vector<light> lights;

    vec3 position = vec3(0.0f, 4.0f, 0.0f);
    vec3 color = vec3(0.6f,0.6f,0.6f);
    light l1 = light(position, color);
    lights.push_back(l1);

    return lights;
}

objectList* initObjectList() {
    objectList *list = new objectList();

    vec3 a = vec3(5,5,1);
    vec3 b = vec3(-5,5,1);
    vec3 c = vec3(5,-5,1);

    vec3 a1 = vec3(5,5,0);
    vec3 a2 = vec3(5,-5,0);
    vec3 a3 = vec3(-5,5,0);

    vec3 cent = vec3(0,0,-3);
    float rad = 0.5;

    triangle *t = new triangle(a,b,c, 1);
    triangle *t1 = new triangle(a1,a2,a3, 1);
    sphere *s = new sphere(cent, rad, 0);
    
    list->append(t);
    list->append(t1);
    list->append(s);



    return list;
}
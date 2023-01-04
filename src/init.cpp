#include "init.hpp"

scene* initScene() {
    scene* myScene = new scene();
    myScene->backgroundColor = vec3(0.05f,0.05f,0.05f);
    myScene->materials = initMaterials();
    myScene->lights = initLights();
    myScene->objs = initObjectList();
    myScene->ambientLight = vec3(1,1,1);
    myScene->cam = initCamera();

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
    ior = 0.7f;

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
    vec3 b1 = vec3(5,-5,0);
    vec3 c1 = vec3(-5,5,0);
    

    vec3 cent = vec3(0,0,-3);
    float rad = 2;

    triangle *t = new triangle(a,b,c,1);
    triangle *t1 = new triangle(a1,b1,c1,1);
    sphere *s = new sphere(cent,rad,0);
    
    list->append(t);
    list->append(t1);
    list->append(s);

    return list;
}

camera initCamera() {
    int image_height = 405;
    int image_width = 720;
    float fovy = 45.0f;
    vec3 camEye = vec3(0.0f, 2.0f, 6.0f);
    vec3 lookAt = vec3(0.0f, 2.0f, 0.0f);
    vec3 up = vec3(0,1,0);

    // camera(image_height, image_width, fovy, camEye, lookAt, up);
    // camera()
    return camera();
}
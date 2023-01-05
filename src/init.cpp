#include "init.hpp"

scene* initScene() {
    scene* myScene = new scene();
    myScene->backgroundColor = vec3(0.3f,0.3f,0.3f);
    myScene->materials = initMaterials();
    myScene->lights = initLights();
    myScene->objs = initObjectList();
    myScene->ambientLight = vec3(1,1,1);
    myScene->cam = camera();

    return myScene;
}

vector<material> initMaterials() {
    vector<material> materials;

    vec3 diffuse = vec3(1.0f, 1.0f, 1.0f);
    vec3 specular = vec3(0.94f, 0.93f, 0.90f);
    vec3 reflective = vec3();
    float shininess = 50;
    vec3 transparent = vec3();
    float ior = 0.6f;

    material mat0 = material(diffuse, specular, transparent, reflective, shininess, ior);

    diffuse = vec3(0.94f, 0.93f, 0.90f);
    specular = vec3(0.94f, 0.93f, 0.90f);
    reflective = vec3();
    shininess = 50;
    transparent = vec3();
    ior = 0.6f;

    material mat1 = material(diffuse, specular, transparent, reflective, shininess, ior);

    diffuse = vec3(0.1f,0.1f,0.1f);
    specular = vec3(0.1f,0.1f,0.1f);
    reflective = vec3(0.1f,0.1f,0.1f);
    shininess = 50;
    transparent = vec3(0.9f,0.9f,0.9f);
    ior = 0.7f;

    material mat2 = material(diffuse, specular, transparent, reflective, shininess, ior);    

    materials.push_back(mat0);
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

    vec3 a = vec3(-10,0,-10);
    vec3 b = vec3(-10,0,10);
    vec3 c = vec3(10,0,-10);
    triangle *ground_t0 = new triangle(a,b,c,0);

    a = vec3(-10,0,-10);
    b = vec3(10,0,-10);
    c = vec3(10,0,-10);
    triangle *ground_t1 = new triangle(a,b,c,0);

    a = vec3(3,3,-3);
    b = vec3(1,0,-3);
    c = vec3(3,0,-1);
    triangle *pyramid_t0 = new triangle(a,b,c,1);

    a = vec3(3,3,-3);
    b = vec3(3,0,-1);
    c = vec3(5,0,-3);
    triangle *pyramid_t1 = new triangle(a,b,c,1);

    a = vec3(3,3,-3);
    b = vec3(5,0,-3);
    c = vec3(3,0,-5);
    triangle *pyramid_t2 = new triangle(a,b,c,1);

    a = vec3(3,3,-3);
    b = vec3(3,0,-5);
    c = vec3(1,0,-3);
    triangle *pyramid_t3 = new triangle(a,b,c,1);

    vec3 cent = vec3(-0.0f, -1.0f, 0.5f);
    float rad = 0.5f;
    sphere *s0 = new sphere(cent,rad,1);

    list->append(ground_t0);
    list->append(ground_t1);
    list->append(pyramid_t0);
    list->append(pyramid_t1);
    list->append(pyramid_t2);
    list->append(pyramid_t3);
    list->append(s0);

    return list;
}

camera initCamera() {
    int image_height = 405;
    int image_width = 720;
    float fovy = 45.0f;
    vec3 camEye = vec3(0.0f, 1.0f, 6.0f);
    vec3 lookAt = vec3(0.0f, 1.0f, 0.0f);
    vec3 up = vec3(0,1,0);

    return camera(image_height, image_width, fovy, camEye, lookAt, up);
}
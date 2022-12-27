#include "init.hpp"

objectList initObjectList() {
    objectList list = objectList();

    vec3 a = vec3(-2,2,0);
    vec3 b = vec3(-2,1,0);
    vec3 c = vec3(-1,2,0);

    vec3 a1 = vec3(2,-1,0);
    vec3 a2 = vec3(2,-2,0);
    vec3 a3 = vec3(1,-2,0);

    vec3 cent = vec3(0,0,0);
    float rad = 1.0f;

    triangle t = triangle(a,b,c);
    triangle t1 = triangle(a1,a2,a3);
    sphere s = sphere(cent, rad);
    
    list.append(&t);
    list.append(&t1);
    list.append(&s);

    return list;
}
#include "triangle.hpp"

triangle::triangle(vec3 _a, vec3 _b, vec3 _c) {
    p1 = _a;
    p2 = _b;
    p3 = _c;
}

// Returns distance to triangle or NaN for no intersection.
float triangle::test_intersection(ray r) {
    vec3 dir = r.direction;
    vec3 orig = r.origin;

    float a = p1.x - p2.x;
    float b = p1.y - p2.y;
    float c = p1.z - p2.z;
    float d = p1.x - p3.x;
    float e = p1.y - p3.y;
    float f = p1.z - p3.z;
    float g = dir.x;
    float h = dir.y;
    float i = dir.z;
    float j = p1.x - orig.x;
    float k = p1.y - orig.y;
    float l = p1.z - orig.z;

    float m = a*(e*i-h*f) + b*(g*f-d*i) + c*(d*h-e*g);

    float beta = (j*(e*i-h*f) + k*(g*f-d*i) + l*(d*h-e*g)) / m;
    float gamma = (i*(a*k-j*b) + h*(j*c-a*l) + g*(b*l-k*c)) / m;
    float t = -1.0f * ((f*(a*k-j*b) + e*(j*c-a*l) + d*(b*l-k*c)) / m);

    // std::cout << t << "  " << beta << "  " << gamma << std::endl;

    // Check if ray validly intersects the triangle.
    if (beta < 0.0f || gamma < 0.0f || beta + gamma > 1.0f || t < 0.0005f) {
    return NAN;
    } 
    return t;
}
#include "triangle.hpp"

triangle::triangle(vec3 _a, vec3 _b, vec3 _c, int _matIndex) {
    p1 = _a;
    p2 = _b;
    p3 = _c;
    t0 = vec3();
    t1 = vec3();
    t2 = vec3();

    matIndex = _matIndex;
}

triangle::triangle(vec3 _a, vec3 _b, vec3 _c, vec3 _t0, vec3 _t1, vec3 _t2, int _matIndex) {
    p1 = _a;
    p2 = _b;
    p3 = _c;
    t0 = _t0;
    t1 = _t1;
    t2 = _t2;

    matIndex = _matIndex;
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

vec3 triangle::getNormal(vec3 point) {
    return unit_vector(cross(p2-p1, p3-p1));
}

vec3 triangle::getTextureCoordinates(ray r) {
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
    float alpha = 1.0f - beta - gamma;

    return vec3(alpha * t0.x + beta * t1.x * gamma * t2.x, alpha * t0.y + beta * t1.y * gamma * t2.y, 0);
}
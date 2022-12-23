#include "sphere.hpp"

sphere::sphere(vec3 c, float r) {
    center = c;
    radius = r;
}

float sphere::test_intersection(ray r) {
    // d = dir
    // e = origin
    // c = center
    // R = radius
    vec3 dir = r.direction;
    vec3 orig = r.origin;

    float first_d = pow(dot(dir, (orig-center)), 2);
    float second_d = dot(dir, dir) * (dot((orig-center), (orig-center)) - pow(radius,2));
    float discriminant = first_d - second_d;   
    if (discriminant < 0 || discriminant == 0) {
        return NAN;
    }

    float first_num = dot(-dir, orig - center);
    float denom = dot(dir, dir);

    float t_0 = (first_num - sqrt(discriminant)) / denom;
    float t_1 = (first_num + sqrt(discriminant)) / denom;

    if (t_1 < 0.0005f) {
        return NAN;
    }
    if (t_0 < 0.0005f) {
        return t_1;
    }
    return t_0;
}
#include "rayTrace.hpp"

vec3 rayTrace(ray r, scene *myScene, int recurseDepth) {
    objectList *objs = myScene->objs;
    vector<material> mats = myScene->materials;
    vector<light> lights = myScene->lights;

    //test intersections
    float t = objs->closestIntersection(r);
    if (isnan(t)) {
        return backgroundColor;
    }

    object* object = objs->getClosest();
    vec3 point = r.at(t);
    vec3 normal = object->getNormal(point);
    material mat = mats.at(object->getMatIndex());
    
    vec3 res = vec3(0,0,0);

    res = res + mat.diffuseCol * myScene->ambientLight;

    /* Iterate through each light and if it can see the point
    add its diffuse and specular component to the point */
    float lightT;
    ray lightRay;
    vec3 toLight;
    vec3 e = unit_vector(myScene->camEye - point);
    vec3 totalDiffuse = vec3();
    vec3 totalSpecular = vec3();
    for (int i = 0; i < lights.size(); i++) {
        light currLight = lights.at(i);
        lightRay = ray(currLight.location, unit_vector(point - currLight.location));
        lightT = objs->closestIntersection(lightRay);
        toLight = unit_vector(currLight.location - point);
        vec3 h = unit_vector(e + toLight);
        if (!isnan(lightT)) {
            //Same point
            if (point.equals(lightRay.at(lightT))) {
                totalDiffuse += currLight.color * max(0.0f, dot(normal, toLight));
                totalSpecular += currLight.color * max(0.0f, pow(dot(h, normal), mat.shininess));
            }
        }
    }

    res += totalDiffuse * mat.diffuseCol;
    res += totalSpecular * mat.specularCol;

    if (recurseDepth < 5) {
        // Reflection
        ray reflected_r = ray();
        vec3 dir = r.direction;
        vec3 pointToEye = unit_vector(r.origin - point);
        reflected_r.origin = point;
        reflected_r.direction = dir - 2 * (dot(dir, normal)) * normal;

        vec3 colorSeen = rayTrace(reflected_r, myScene, recurseDepth + 1);

        // Refraction
        

        if (!colorSeen.equals(backgroundColor)) {
            res += mat.reflectiveCol * colorSeen;
        }

        vec3 refracted = refract(r.direction, normal, mat.refractionIndex);
        ray refractRay = ray(point, refracted);
        vec3 colorSeen1 = rayTrace(refractRay, myScene, recurseDepth + 1);

        // std::cout << r.direction << "    " << refracted << std::endl;

        if (!colorSeen1.equals(backgroundColor)) {
            res += mat.transparentCol * colorSeen1;
        }
    }
    return res;
}

// Take the incident ray, normal vector, and 
vec3 refract(vec3 incident, vec3 normal, float ior) {
    float cos_theta_i = dot(incident, normal);
    float refraction_ratio = cos_theta_i < 0 ? ior : 1.0f/ior;
    float sin_theta = sqrt(1 - pow(cos_theta_i, 2));
    vec3 t;

    // refraction_ratio * sin_theta > 1.0f
    if (refraction_ratio * sin_theta > 1.0f) {
        std::cout << "fuck" << std::endl;
    } else {
        // Must refract
        float sin_theta_t_2 = pow(refraction_ratio, 2) * (1 - pow(cos_theta_i, 2));
        t = pow(refraction_ratio, 2) * incident + (refraction_ratio * cos_theta_i - sqrt(1 - sin_theta_t_2)) * normal;
    }
    
    return unit_vector(t);
}

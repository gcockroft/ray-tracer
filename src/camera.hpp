#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.hpp"
#include "ray.hpp"

class camera {
  public:
    float fovy;
    vec3 camEye;
    vec3 lookAt;
    vec3 up;
    vec3 left;
    float screenHeight;
    float screenWidth;
    vec3 topLeft;

    camera() {}
    camera(int image_height, int image_width) {
      fovy = 45.0f * 3.14159265358979323 / 180;
      camEye = vec3(0.0f, 0.0f, 5.0f);
      lookAt = vec3(0.0f, 0.0f, 0.0f);
      up = vec3(0.0f, 1.0f, 0.0f);
      left = vec3(-1.0f, 0.0f, 0.0f);

      screenHeight = 2 * ((lookAt - camEye).length() * tan(fovy/2));
      screenWidth = (image_width * screenHeight) / image_height;
      topLeft = lookAt + (screenHeight/2 * up) + (screenWidth/2 * left);
    };

    ray getRay(vec3 pos) {
      ray r;
      r.direction = unit_vector(pos - camEye);
      r.origin = camEye;
      return r;
    };
};

#endif
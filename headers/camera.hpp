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

    camera() {
      int image_width = 256;
      int image_height = 256;
      float PI = 3.1415926535897932384626433832795;

      fovy = 45.0f * (float)PI / 180;
      camEye = vec3(0.0f, 0.0f, 3.0f);
      lookAt = vec3(0.0f, 0.0f, 0.0f);
      up = vec3(0.0f, 1.0f, 0.0f);
      left = vec3(-1.0f, 0.0f, 0.0f);

      screenHeight = 2 * ((lookAt - camEye).length() * tan(fovy/2));
      screenWidth = (image_width * screenHeight) / image_height;
      topLeft = lookAt + (screenHeight/2 * up) + (screenWidth/2 * left);
    }

    camera(int image_height, int image_width, float fovy, vec3 camEye, vec3 lookAt, vec3 up) {
      float PI = 3.1415926535897932384626433832795;
      std::cout << up << std::endl;
      camera::fovy = fovy * PI / 180;
      camera::camEye = camEye;
      camera::lookAt = lookAt;
      camera::up = up;
      camera::left = unit_vector(cross(up, lookAt - camEye));

      std::cout << camera::up << std::endl;

      camera::screenHeight = 2 * ((lookAt - camEye).length() * tan(fovy/2));
      camera::screenWidth = (image_width * screenHeight) / image_height;
      camera::topLeft = lookAt + (screenHeight/2 * up) + (screenWidth/2 * left);
    };

    ray getRay(vec3 pos) {
      ray r;
      r.direction = unit_vector(pos - camEye);
      r.origin = camEye;
      return r;
    };
};

inline std::ostream& operator<<(std::ostream &out, const camera cam) {
    return out << cam.screenHeight << ' ' << cam.screenWidth << ' ' << std::endl << " camEye: " << cam.camEye << " lookAt: " << cam.lookAt << " up: " << cam.up << " left: " << cam.left << " topLeft: " << cam.topLeft << std::endl << cam.fovy;
}

#endif
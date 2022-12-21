#include <iostream>
#include "image.hpp"
#include "vec.hpp"
#include <vector>
#include "main.hpp"
#include "ray.hpp"
#include "rayTrace.hpp"
 using namespace std;


int main() {
  // Image
  const int image_width = 256;
  const int image_height = 256;

  vector<vector<vec3>> image;

  for (int i = 0; i < image_height; i++) {
    image.push_back(vector<vec3>());
    for (int j = 0; j < image_width; j++) {
      image[i].push_back(vec3());
    }
  }

  std::cout << image[0][0] << "    " << image[240][240] << std::endl;
  image[0][0] = vec3(255,255,255);

  //Calc window dimensions
  //Hard coded camera values for now
  vec3 camEye = vec3(0.0f, 0.0f, 5.0f);
  vec3 lookAt = vec3(0.0f, 0.0f, 0.0f);
  vec3 up = vec3(0,1,0);
  float fovy = 45.0f;

  fovy = fovy * PI / 180;
  vec3 camDir = unit_vector(lookAt - camEye);
  vec3 left = unit_vector(cross(up, camDir));

  float height = 2 * ((lookAt - camEye).length() * tan(fovy/2));
  float width = (image_width * height) / image_height;

  float pixelWidth = width / image_width;
  float pixelHeight = height / image_height;

  vec3 topLeft = lookAt + (height/2 * up) + (width/2 * left);
  vec3 currPosition;
  ray r;

  for (int y = 0; y < image_height; y++) {

    for (int x = 0; x < image_width; x++) {
      currPosition = topLeft - (pixelWidth/2 * left * float(x)) - (pixelHeight/2 * up * float(y));
      r.direction = unit_vector(currPosition - camEye);
      r.origin = camEye;

      vec3 color = rayTrace(r , x , y);
      image[x][y] = color;
    }
  }

  

  // Render
  write_to_file(image_width, image_height, image);

  return 1;
}
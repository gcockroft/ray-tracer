#include "main.hpp"

 using namespace std;


int main() {
  // Image
  const int image_width = 256;
  const int image_height = 256;

  //Initialize pixel array
  vector<vector<vec3>> image;
  for (int i = 0; i < image_height; i++) {
    image.push_back(vector<vec3>());
    for (int j = 0; j < image_width; j++) {
      image[i].push_back(vec3());
    }
  }

  //Calc window dimensions
  //Hard coded camera values for now
  vec3 camEye = vec3(0.0f, 0.0f, 5.0f);
  vec3 lookAt = vec3(0.0f, 0.0f, 0.0f);
  //vec3 camDir = unit_vector(lookAt - camEye);
  vec3 up = vec3(0,1,0);
  vec3 left = vec3(-1,0,0);
  float fovy = 45.0f;
  fovy = fovy * PI / 180;
  
  //In world height and width of virtual screen
  float height = 2 * ((lookAt - camEye).length() * tan(fovy/2));
  float width = (image_width * height) / image_height;

  //In world height and width of pixel
  float pixelWidth = width / image_width;
  float pixelHeight = height / image_height;

  vec3 topLeft = lookAt + (height/2 * up) + (width/2 * left);
  vec3 currPosition;
  
  scene* myScene = initScene();

  float horizontalScalar;
  float verticalScalar;

  ray r;
  for (int y = 0; y < image_height; y++) {
    for (int x = 0; x < image_width; x++) {
      horizontalScalar = (float(x) + 0.5f) * pixelWidth;
      verticalScalar = (float(y) + 0.5f) * pixelHeight;
      currPosition = topLeft - (horizontalScalar * left) - (verticalScalar * up);

      r.direction = unit_vector(currPosition - camEye);
      r.origin = camEye;
      vec3 color = rayTrace(r, myScene, 0);
      image[x][y] = color;
    }
  }
  
  // Render
  write_to_file(image_width, image_height, image);

  return 1;
}
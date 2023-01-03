#include "main.hpp"

 using namespace std;


int main() {
  // Image
  const int image_height = 256;
  const int image_width = 256;
  const int samples_per_pixel = 1;

  //Initialize pixel array
  vector<vector<vec3>> image;
  for (int i = 0; i < image_height; i++) {
    image.push_back(vector<vec3>());
    for (int j = 0; j < image_width; j++) {
      image[i].push_back(vec3());
    }
  }

  // Provide camera with image height to calculate screen dimensmions.
  camera cam(image_height, image_width); 
  scene* myScene = initScene(cam.camEye);
  
  //In world height and width of pixel
  float pixelWidth = cam.screenWidth / image_width;
  float pixelHeight = cam.screenHeight / image_height;
   
  vec3 currPosition;
  float horizontalScalar;
  float verticalScalar;
  ray r;
  for (int y = 0; y < image_height; y++) {
    for (int x = 0; x < image_width; x++) {
      vec3 pixelColor = vec3(0,0,0);
      for (int s = 0; s < samples_per_pixel; s++) {
        horizontalScalar = (float(x) + random_double()) * pixelWidth;
        verticalScalar = (float(y) + random_double()) * pixelHeight;
        currPosition = cam.topLeft - (horizontalScalar * cam.left) - (verticalScalar * cam.up);
        r = cam.getRay(currPosition);
        pixelColor += rayTrace(r, myScene, 0);
      }
      pixelColor /= samples_per_pixel;
      image[x][y] = pixelColor;
      
    }
    std::cout << y << std::endl;
  }
  
  // Render
  write_to_file(image_width, image_height, image);

  return 1;
}
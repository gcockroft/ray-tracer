#include <iostream>
#include "image.hpp"
#include "vec.hpp"
#include <vector>
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
  // image[255][255] = vec3(255,255,255);
  

  // Render
  write_to_file(image_width, image_height, image);

  return 1;
}
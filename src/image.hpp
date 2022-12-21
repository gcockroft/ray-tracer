#ifndef IMAGE
#define IMAGE

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

#include "vec3.hpp" 

// TODO: Another param here for image data
int write_to_file(int image_width, int image_height, std::vector<std::vector<vec3>> image) {
  if (remove("image.ppm") == 0) {
    std::cout << "Removed file" << std::endl;
  } else {
    std::cout << "Fuck you" << std::endl;
  }

  std::ofstream ImageFile("image.ppm", std::ofstream::trunc);

  ImageFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; ++j) {
      for (int i = 0; i < image_width; ++i) {

          int ir = static_cast<int>(image[i][j].x);
          int ig = static_cast<int>(image[i][j].y);
          int ib = static_cast<int>(image[i][j].z);

          ImageFile << ir << ' ' << ig << ' ' << ib << '\n';
      }
  }
  ImageFile.close();
  return 1;
}

#endif
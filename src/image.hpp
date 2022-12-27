#ifndef IMAGE
#define IMAGE

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

#include "vec3.hpp" 

using namespace std;

// TODO: Another param here for image data
int write_to_file(int image_width, int image_height, vector<vector<vec3>> image) {
  if (remove("image.ppm") == 0) {
    cout << "Removed file" << endl;
  } else {
    cout << "Fuck you" << endl;
  }

  ofstream ImageFile("image.ppm", ofstream::trunc);

  ImageFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; ++j) {
      for (int i = 0; i < image_width; ++i) {

          //255.999?
          int ir = static_cast<int>(image[i][j].x * 255);
          int ig = static_cast<int>(image[i][j].y * 255);
          int ib = static_cast<int>(image[i][j].z * 255);

          ImageFile << ir << ' ' << ig << ' ' << ib << '\n';
      }
  }
  ImageFile.close();
  return 1;
}

#endif
#include <iostream>
#include <fstream>

// TODO: Another param here for image data
int write_to_file(int image_width, int image_height) {
  std::ofstream ImageFile("image.ppm");

  ImageFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = image_height-1; j >= 0; --j) {
      for (int i = 0; i < image_width; ++i) {
          auto r = double(i) / (image_width-1);
          auto g = double(j) / (image_height-1);
          auto b = 0.25;

          int ir = static_cast<int>(255.999 * r);
          int ig = static_cast<int>(255.999 * g);
          int ib = static_cast<int>(255.999 * b);

          ImageFile << ir << ' ' << ig << ' ' << ib << '\n';
      }
  }
  ImageFile.close();
  return 1;
}
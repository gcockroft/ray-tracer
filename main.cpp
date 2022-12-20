#include <iostream>
#include "image.hpp"
#include "vec.hpp"


int main() {
  // Image
  const int image_width = 256;
  const int image_height = 256;

  // Render
  write_to_file(image_width, image_height);

  return 1;
}
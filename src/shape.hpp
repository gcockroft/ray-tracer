#ifndef SHAPE
#define SHAPE

#include "ray.hpp"

class Shape {
  public: 

    Shape() {}
    float test_intersection(ray r) {std::cout << ":(" << std::endl;}
};

#endif
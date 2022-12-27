#include "objects.hpp"

shape* objects::shapeAt(int index) {
  return shapes.at(index);
}

void objects::append(shape* shape) {
  shapes.push_back(shape);
}

float objects::closestIntersection(ray r) {
  float minT = 99999999;
  float t = NAN;
  for (int i = 0; i < shapes.size(); i++) {
      shape* curr = shapes.at(i);
      
      t = curr->test_intersection(r);
      if (t < minT) {
          closestIndex = i;
          minT = t;
      }
  }

  if (minT != 99999999) {
      return minT;
  }
  return NAN;
}

shape* objects::getClosest() {
  return shapes.at(closestIndex);
}
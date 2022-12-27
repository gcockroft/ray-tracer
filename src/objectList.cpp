#include "objectList.hpp"

objectList::objectList() {}

object* objectList::objectAt(int index) {
  return objectVec.at(index);
}

void objectList::append(object* object) {
  objectVec.push_back(object);
}

float objectList::closestIntersection(ray r) {
  float minT = 99999999;
  float t = NAN;
  for (int i = 0; i < objectVec.size(); i++) {
      object* curr = objectVec.at(i);
      
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

object* objectList::getClosest() {
  return objectVec.at(closestIndex);
}
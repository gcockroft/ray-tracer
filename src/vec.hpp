#ifndef VEC
#define VEC

#include <cmath>
#include <iostream>

class vec {
  public:
    float x;
    float y;
    float z;

    vec() {
      x = 0;
      y = 0;
      z = 0;
    }

    vec(float _x, float _y, float _z) {
      x = _x;
      y = _y;
      z = _z;
    }

    vec operator-() const {return vec(-x, -y, -z);}

    vec operator+=(const vec &v) {
      this->x += v.x;
      this->y += v.y;
      this->z += v.z;
    }

    vec operator-=(const vec &v) {
      this->x -= v.x;
      this->y -= v.y;
      this->z -= v.z;
    }

    vec operator*=(const float s) {
      this->x *= s;
      this->y *= s;
      this->z *= s;
    }

    vec operator/=(const float s) {
      return *this *= (1.0f/s);
    }

    float length() {
      float lengthSquared = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
      return sqrt(lengthSquared);
    }
};

inline std::ostream& operator<<(std::ostream &out, const vec &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline vec operator+(const vec &u, const vec &v) {
  return vec(u.x + v.x, u.y+v.y, u.x+v.z);
}

inline vec operator-(const vec &u, const vec &v) {
  return vec(u.x - v.x, u.y-v.y, u.x-v.z);
}

inline vec operator*(const vec &u, const vec &v) {
  return vec(u.x * v.x, u.y*v.y, u.x*v.z);
}

inline vec operator*(const vec &u, const float s) {
  return vec(u.x * s, u.y * s, u.z * s);
}

inline vec operator*(const float s, const vec &u) {
  return u * s;
}

inline vec operator/(const vec &u, const vec &v) {
  return vec(u.x / v.x, u.y/v.y, u.x/v.z);
}

inline float dot(const vec &u, const vec &v) {
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline vec cross(const vec &u, const vec &v) {
  float x = u.y*v.z - u.z * v.y;
  float y = -(u.x * v.z - u.z*v.x);
  float z = u.x*v.y - u.y*v.x;
  return vec(x,y,z);
}


#endif
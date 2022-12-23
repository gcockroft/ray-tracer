#ifndef VEC3
#define VEC3

#include <cmath>
#include <iostream>

class vec3 {
 

  public:
    float x;
    float y;
    float z;
    
    vec3() {
      x = 0;
      y = 0;
      z = 0;
    }

    vec3(float _x, float _y, float _z) {
      x = _x;
      y = _y;
      z = _z;
    }

    vec3 operator-() const {return vec3(-x, -y, -z);}

    vec3 operator+=(const vec3 &v) {
      this->x += v.x;
      this->y += v.y;
      this->z += v.z;
      return *this;
    }

    vec3 operator-=(const vec3 &v) {
      this->x -= v.x;
      this->y -= v.y;
      this->z -= v.z;
      return *this;
    }

    vec3 operator*=(const float s) {
      this->x *= s;
      this->y *= s;
      this->z *= s;
      return *this;
    }

    vec3 operator/=(const float s) {
      return *this *= (1.0f/s);
    }

    

    float length() {
      float lengthSquared = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
      return sqrt(lengthSquared);
    }
};

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
  return vec3(u.x + v.x, u.y+v.y, u.x+v.z);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
  return vec3(u.x - v.x, u.y-v.y, u.z-v.z);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
  return vec3(u.x * v.x, u.y*v.y, u.x*v.z);
}

inline vec3 operator*(const vec3 &u, const float s) {
  return vec3(u.x * s, u.y * s, u.z * s);
}

inline vec3 operator*(const float s, const vec3 &u) {
  return u * s;
}

inline vec3 operator/(const vec3 &u, const vec3 &v) {
  return vec3(u.x / v.x, u.y/v.y, u.x/v.z);
}

inline vec3 operator/(const vec3 &u, const float s) { 
      return vec3(u.x / s, u.y / s, u.z /s);
}

inline float dot(const vec3 &u, const vec3 &v) {
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
  float x = u.y*v.z - u.z * v.y;
  float y = -(u.x * v.z - u.z*v.x);
  float z = u.x*v.y - u.y*v.x;
  return vec3(x,y,z);
}

inline vec3 unit_vector(vec3 v) {
  return v / v.length();
}

using color = vec3;

#endif
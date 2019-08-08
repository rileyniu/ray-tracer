//
//  vec3.h
//  ray-tracer
//
//  Created by Riley Niu on 7/23/19.
//  Copyright © 2019 Riley Niu. All rights reserved.
//
#include <math.h>
#include <stdlib.h>
#include <iostream>

#ifndef vec3_h
#define vec3_h

class vec3 {
public:
    float e[3];
    vec3(){}
    vec3(float e0, float e1, float e2){
        e[0] = e0;
        e[1] = e1;
        e[2] = e2;
    }
    // inline reduces function call overhead
    inline float x() const { return e[0];}
    inline float y() const { return e[1];}
    inline float z() const { return e[2];}
    inline float r() const { return e[0];}
    inline float g() const { return e[1];}
    inline float b() const { return e[2];}
    
    /*
     const in front of data type:
     - returns a const vec3& object, that cannot be altered once declared
     const after func():
     - declares the method as a const member function. A const member function is the one
     which does not modify any member variables of the class (unless they are marked as mutable)
     - should be used with getters
     */
    
    // a variable which stores the address of another variable is called a pointer
    // vec3& means function returns a reference/address instead of value
    inline const vec3& operator+ () const {return *this; } // this is a const member function that returns a const reference
    inline vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]); }
    inline float operator[] (int i) const {return e[i]; }
    inline float& operator[] (int i) { return e[i]; }; // this cannot be a const member function because the returned reference can then be used to modify e
    
    inline vec3& operator+=(const vec3 &v2);
    inline vec3& operator-=(const vec3 &v2);
    inline vec3& operator*=(const vec3 &v2);
    inline vec3& operator/=(const vec3 &v2);
    inline vec3& operator*=(const float t);
    inline vec3& operator/=(const float t);
    
    inline float length() const {
        return sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    }
    inline float squared_length() const {
        return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
    }
    inline void make_unit_vector();
};

// some member functions are declared in the class while some are defined directly outside

inline std::istream& operator>>(std::istream &is, vec3 &t){
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

inline std::ostream& operator<< (std::ostream &os, vec3 &t){
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}

// make this vector a unit vector
inline void vec3::make_unit_vector()
{
    float length = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    float k = 1 / length;
    e[0] *= k; e[1] *= k; e[2] *= k;
}

inline vec3 operator+(const vec3& v1, const vec3& v2){
    return vec3(v1.e[0]+v2.e[0], v1.e[1]+v2.e[1], v1.e[2]+v2.e[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2){
    return vec3(v1.e[0]-v2.e[0], v1.e[1]-v2.e[1], v1.e[2]-v2.e[2]);
}

inline vec3 operator*(const vec3& v1, const vec3& v2){
    return vec3(v1.e[0]*v2.e[0], v1.e[1]*v2.e[1], v1.e[2]*v2.e[2]);
}

inline vec3 operator/(const vec3& v1, const vec3& v2){
    return vec3(v1.e[0]/v2.e[0], v1.e[1]/v2.e[1], v1.e[2]/v2.e[2]);
}

// scalar multiplication
inline vec3 operator*(float k, const vec3& v1){
    return vec3(v1.e[0]*k, v1.e[1]*k, v1.e[2]*k);
}

inline vec3 operator/(const vec3& v1, float k){
    return vec3(v1.e[0]/k, v1.e[1]/k, v1.e[2]/k);
}

inline float dot(const vec3& v1, const vec3& v2){
    return v1.e[0]*v2.e[0]+v1.e[1]*v2.e[1]+v1.e[2]*v2.e[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2){
    return vec3(v1.e[1]*v2.e[2] - v2.e[1]*v1.e[2],
                -v1.e[0]*v2.e[2] + v2.e[0]*v1.e[2],
                v1.e[0]*v1.e[1] - v2.e[0]*v1.e[1]);
}

inline vec3& vec3::operator+=(const vec3& v){
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

inline vec3& vec3::operator-=(const vec3& v){
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const vec3& v){
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

inline vec3& vec3::operator/=(const vec3& v){
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(const float k){
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
}

inline vec3& vec3::operator/=(const float k){
    e[0] /= k;
    e[1] /= k;
    e[2] /= k;
    return *this;
}

inline vec3 unit_vector(vec3 v){
    return v / v.length();
}


#endif /* vec3_h */

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
    
    float e[3];
    
public:
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
    
    inline float length() const {
        return sqrt(e[0]^2+e[1]^2+e[2]^2);
    }
    inline float squared_length() const {
        return e[0]^2+e[1]^2+e[2]^2;
    }
    
    // operator overloading returns the address of the actual object
    // a variable which stores the address of another variable is called a pointer
    // vec3& means function returns a reference/address instead of value
    inline const vec3& operator+ () const {return *this; }
    inline vec3 operator-() const () {return vec3(-e[0], -e[1], -e[2]); }
    inline float operator[] (int i) const {return e[i]; }
    inline float& operator[] (int i) const { return e[i]; };
    
    inline vec3& operator+=(const vec3 &v2);
    inline vec3& operator-=(const vec3 &v2);
    inline vec3& operator*=(const vec3 &v2);
    inline vec3& operator/=(const vec3 &v2);
    inline vec3& operator*=(const float t);
    inline vec3& operator/=(const float t);
    
};

#endif /* vec3_h */

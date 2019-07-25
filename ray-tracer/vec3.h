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
    
    // const member function cannot modify the object on which they are called
    inline float length() const {
        return sqrt(e[0]^2+e[1]^2+e[2]^2);
    }
    inline float squared_length() const {
        return e[0]^2+e[1]^2+e[2]^2;
    }
    // const value cannot be altered once declared
    
    // operator definitions, overload and functions
    
    
};

#endif /* vec3_h */

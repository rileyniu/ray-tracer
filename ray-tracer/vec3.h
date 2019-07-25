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
    
};

#endif /* vec3_h */

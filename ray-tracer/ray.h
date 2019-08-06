//
//  ray.h
//  ray-tracer
//
//  Created by Riley Niu on 8/5/19.
//  Copyright © 2019 Riley Niu. All rights reserved.
//

#ifndef ray_h
#define ray_h
#include "vec3.h"

class ray {
    <#instance variables#>
    
public:
    vec3 A;
    vec3 B;
    ray() {}
    ray(const vec3& a, const vec3& b){
        A = a; B = b;
    }
    vec3 origin() const { return A; }
    vec3 direction() const { return b; }
    vec3 point_at_parameter(float t) const{return A + t*B; }
};


#endif /* ray_h */

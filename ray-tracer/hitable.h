//
//  hitable.h
//  ray-tracer
//
//  Created by Riley Niu on 1/11/20.
//  Copyright © 2020 Riley Niu. All rights reserved.
//

#ifndef hitable_h
#define hitable_h
#include "ray.h"


// abstract class for all hitable objects
// if hit, compute a hit record
struct hit_record {
    float t;
    vec3 p;
    vec3 normal;
}

class hitable {
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const {};
};

#endif /* hitable_h */

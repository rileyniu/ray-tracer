//
//  sphere.h
//  ray-tracer
//
//  Created by Riley Niu on 1/11/20.
//  Copyright © 2020 Riley Niu. All rights reserved.
//

#ifndef sphere_h
#define sphere_h

#include "hitable.h"

class sphere: public hitable {
    public:
        vec3 center;
        float radius;
        sphere(){}
        sphere(const vec3& c, const vec3& r){
            center = c; raduis = r;
        }
    //    hit()
};




#endif /* sphere_h */

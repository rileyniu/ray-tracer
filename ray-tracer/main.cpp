//
//  main.cpp
//  ray-tracer
//
//  Created by Riley Niu on 7/22/19.
//  Copyright © 2019 Riley Niu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "vec3.h"
#include "ray.h"

using namespace std;
// A simple color(ray) function that returns the background blue color by
// linearly blends white and blue depending on the up/downess of the y coordinate.
vec3 color(const ray& r){
    vec3 unit_dir = unit_vector(r.direction());
    float t = 0.5* (unit_dir.y()+1.0);
    return (1.0-t)*vec3(1.0, 1.0, 1.0)+t*vec3(0.5, 0.7, 1.0);
}

// to create this image by a ray tracer: from each pixel, back trace a ray to the origin,
// then compute the color of the pixel
int main() {
    int nx = 200;
    int ny = 100;
    ofstream img ("raytracer.ppm");
    img << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny-1; j>=0;--j){
        for (int i = 0;i < nx; ++i){
            // define the coordinate system, image plane is at z=-1
            vec3 origin(0.0, 0.0, 0.0);
            vec3 left_bottom(-2.0, -1.0, -1.0);
            vec3 horizontal(4.0, 0.0, 0.0);
            vec3 vertical(0.0, 2.0, 0.0);
            float u = float(i)/float(nx);
            float v = float(j)/float(ny);
            // transform pixel coordinates to 3d coordinates, as we know the left_bottom coordinate
            vec3 pixel_coor = left_bottom+u*horizontal+v*vertical;
            ray r(origin, pixel_coor);
            vec3 col = color(ray(origin, pixel_coor));
            
            //vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            
           img << ir << " " << ig << " " << ib << "\n";
        }
    }
    return 0;
}



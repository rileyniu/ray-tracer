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

/* Chapter 4:
   p(t) = A+t*B
   dot((p(t)-origin),(p(t)-origin)) = R*R => (A-C)*(A-C)+ 2tB*(A-C)+ t^2 B*B - R*R = 0
   determine how many roots the quadratic function has.
 
 Chapter 5:
 If we hit a sphere return the point P on it, then obtain the surface normal by P-O
 */
float hit_sphere(const vec3& origin, float radius, const ray& r){
    float a = dot(r.direction(), r.direction());
    float b = 2.0*dot(r.direction(), r.origin()-origin);
    float c = dot(r.origin()-origin, r.origin()-origin);
    float t = b*b-4*a*c;
    if (t<0) {
        return -1;
    }else{
        return (-b-sqrt(t))/2*a;
    }
}

// A simple color(ray) function that returns the background blue color by
// linearly blends white and blue depending on the up/downess of the y coordinate.
vec3 color(const ray& r){
    float t = hit_sphere(vec3(0,0,-1), 0.5, r);
    if (t>0){
        // unit sphere normal, mapped to (0,1) to visualize
        vec3 norm = normalize(r.point_at_t(t)-vec3(0,0,-1));
        return 0.5*(norm+vec3(1.0, 1.0, 1.0));
    }
    vec3 unit_dir = normalize(r.direction());
    t = 0.5* (unit_dir.y()+1.0);
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



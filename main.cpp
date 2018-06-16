#include <algorithm>
#include <memory>
#include <iostream>
#include "vec.h"
#include "ray.h"
#include "sphere.h"
#include "image.h"
#include "camera.h"
#include "hit.h"
#include "accel.h"

Vec reflect(const Vec& d, const Vec& n) {
    return d - n * 2 * d.dot(n);
}

int main() {
    Image img(512, 512);
    Camera cam(Vec(0., 0., -3.), Vec(0., 0., 1.));

    Sphere sph(3.0, Vec(0., 0., 3.));
    Accel accel;
    accel.add(std::make_shared<Sphere>(Sphere(1., Vec(0, 0, 0))));
    accel.add(std::make_shared<Sphere>(Sphere(1000., Vec(0, -1001, 0))));

    Vec lightDir = Vec(-1, 0.5, -1).norm();

    for(int y=1; y<=img.height; y++) {
        for(int x=1; x<=img.width; x++) {
            float u = (2.0*x - img.width)/img.width;
            float v = (2.0*y - img.height)/img.height;
            Ray ray = cam.getRay(u, v);
            Hit hit;

            if(accel.intersect(ray, hit)) {
                Ray shadowRay = Ray(hit.hitPos+hit.hitNorm*0.001, lightDir);
                Hit hit_shadow;

                if(!accel.intersect(shadowRay, hit_shadow)) {
                    float I = std::max(lightDir.dot(hit.hitNorm), (float)0.);
                    img.setPixel(x, y, Vec(1., 1., 1.)*I);

                    // img.setPixel(x, y, (hit.hitNorm + Vec(1., 1., 1.))/2.0 );
                    // std::cout 
                    //     << ((hit.hitNorm + Vec(1., 1., 1.))/2.0).x 
                    //     << " " 
                    //     << ((hit.hitNorm + Vec(1., 1., 1.))/2.0).y 
                    //     << " " 
                    //     << ((hit.hitNorm + Vec(1., 1., 1.))/2.0).z 
                    //     << "\n"; 
                } else {
                   img.setPixel(x, y, Vec(0., 0., 0.));
                }
            } else {
                img.setPixel(x, y, Vec(0., 0., 0.));
            }
        }
    }

    img.ppm_output();

    return 0;
}

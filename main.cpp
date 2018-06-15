#include <algorithm>
#include "vec.h"
#include "ray.h"
#include "sphere.h"
#include "image.h"
#include "camera.h"
#include "hit.h"

int main() {
    Image img(512, 512);
    Camera cam(Vec(0., 0., 0.), Vec(0., 0., 1.));
    Sphere sph(1.0, Vec(0., 0., 3.));
    Vec lightDir = Vec(1, 1, -1).norm();

    for(int y=1; y<=img.height; y++) {
        for(int x=1; x<=img.width; x++) {
            float u = (2.0*x - img.width)/img.width;
            float v = (2.0*y - img.height)/img.height;
            Ray ray = cam.getRay(u, v);
            Hit hit;

            if(sph.intersect(ray, hit)) {
                float I = std::max(lightDir.dot(hit.hitNorm), (float)0.);
                img.setPixel(x, y, (Vec(1., 1., 1.) * I));
                // std::cout << ((hit.hitNorm + Vec(1., 1., 1.))/2.0).x << " " << ((hit.hitNorm + Vec(1., 1., 1.))/2.0).y << " " << ((hit.hitNorm + Vec(1., 1., 1.))/2.0).z << "\n"; 
            } else {
                img.setPixel(x, y, Vec(0., 0., 0.));
            }
        }
    }

    img.ppm_output();

    return 0;
}

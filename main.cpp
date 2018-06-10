#include "vec.h"
#include "ray.h"
#include "sphere.h"
#include "image.h"
#include "camera.h"

int main() {
    Image img(512, 512);
    Camera cam(Vec(0., 0., 0.), Vec(0., 0., 1.));
    Sphere sph(1.0, Vec(0., 0., 5.));

    for(int y=1; y<=img.height; y++) {
        for(int x=1; x<=img.width; x++) {
            float u = (2.0*x - img.width)/img.width;
            float v = (2.0*y - img.height)/img.height;
            Ray ray = cam.getRay(u, v);

            if(sph.intersect(ray)) {
                img.setPixel(x, y, Vec(255., 255., 255.));
            } else {
                img.setPixel(x, y, Vec(0., 0., 0.));
            }
        }
    }

    img.ppm_output();

    return 0;
}

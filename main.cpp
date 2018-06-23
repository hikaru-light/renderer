#include <algorithm>
#include <memory>
#include <iostream>
#include <random>

#include "vec.h"
#include "ray.h"
#include "sphere.h"
#include "image.h"
#include "camera.h"
#include "hit.h"
#include "accel.h"

std::random_device dev_rnd;
std::mt19937 mt(dev_rnd());
std::uniform_real_distribution<> dist(0, 1);

float rnd() {
    return dist(mt);
}

Vec reflect(const Vec& d, const Vec& n) {
    return d - n * 2 * d.dot(n);
}

Vec randomDir() {
    float theta = 2 * M_PI * rnd();
    float phi = std::acos(1-rnd());

    float x = std::sin(theta)*std::cos(phi);
    float y = std::cos(theta);
    float z = std::sin(theta)*std::sin(phi);
    
    return Vec(x, y, z);
}

int main() {
    Image img(512, 512);
    Camera cam(Vec(0., 0., -3.), Vec(0., 0., 1.));

    // Sphere sph(3.0, Vec(0., 0., 3.));
    Accel accel;
    accel.add(std::make_shared<Sphere>(Sphere(1., Vec(0, 0, 1), Vec(0, 1, 0))));
    accel.add(std::make_shared<Sphere>(Sphere(10000., Vec(0, -10001, 0), Vec(1, 1, 1))));

    // Vec lightDir = Vec(-1, 0.5, -1).norm();

    #pragma omp parallel for
    for (int i = 0; i < 100; i++)
    {
        for (int y = 1; y <= img.height; y++)
        {
            for (int x = 1; x <= img.width; x++)
            {
                float u = (2.0 * (x+rnd()) - img.width) / img.width;
                float v = (2.0 * (y+rnd()) - img.height) / img.height;
                Ray ray = cam.getRay(u, v);
                Hit hit;
                Vec color;

                if (accel.intersect(ray, hit))
                {
                    Vec lightDir = randomDir();
                    Ray shadowRay = Ray(hit.hitPos + hit.hitNorm * 0.01, lightDir);
                    Hit hit_shadow;

                    if (!accel.intersect(shadowRay, hit_shadow))
                    {
                        float I = std::max(lightDir.dot(hit.hitNorm), (float)0.);
                        color = hit.hitSph -> sphCol * I;

                        // img.setPixel(x, y, (hit.hitNorm + Vec(1., 1., 1.))/2.0 );
                    }
                    else
                    {
                        color = Vec(0., 0., 0.);
                    }
                }
                else
                {
                    color = Vec(1., 1., 1.);
                }

                img.setPixel(x, y, img.getPixel(x, y)+color/100);
            }
        }
    }

    img.ppm_output();

    return 0;
}

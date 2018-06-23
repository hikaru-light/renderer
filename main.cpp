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

Vec color;
Accel accel;

float rnd()
{
    return dist(mt);
}

Vec reflect(const Vec &d, const Vec &n)
{
    return d - n * 2 * d.dot(n);
}

Vec randomDir()
{
    float theta = 2 * M_PI * rnd();
    float phi = std::acos(1 - rnd());

    float x = std::sin(theta) * std::cos(phi);
    float y = std::cos(theta);
    float z = std::sin(theta) * std::sin(phi);

    return Vec(x, y, z);
}

void orthonormalBasis (Vec& n, Vec& x, Vec& z) {
    if(n.x > 0.9) x = Vec(0, 1, 0);
    else x = Vec(1, 0, 0);

    x = x - n * x.dot(n);
    x = x.norm();
    z = n.cross(x).norm();
}

Vec randomHemisphere(Vec& n) {
    float u = rnd();
    float v = rnd();

    float x = std::sqrt(1-u*u) * std::cos(2*M_PI*v);
    float y = u;
    float z = std::sqrt(1-u*u) * std::sin(2*M_PI*v);

    Vec xv, zv;
    orthonormalBasis(n, xv,zv);

    return xv*x + n*y + zv*z;
}

Vec getColor(const Ray& ray, int depth = 0)
{
    if(depth > 100) return Vec(0, 0, 0);

    Hit hit;
    if (accel.intersect(ray, hit))
    {
        if (hit.hitSph->sphMat == 0)
        {
            Ray nextRay(hit.hitPos +hit.hitNorm * 0.01, randomHemisphere(hit.hitNorm));
            float cos_term = std::max(nextRay.rayDir.dot(hit.hitNorm), (float)0.0);
            
            return hit.hitSph -> sphCol * getColor(nextRay, depth+1) * cos_term;

            // Vec lightDir = randomDir();
            // Ray shadowRay = Ray(hit.hitPos + hit.hitNorm * 0.01, lightDir);
            // Hit hit_shadow;

            // if (!accel.intersect(shadowRay, hit_shadow))
            // {
            //     float I = std::max(lightDir.dot(hit.hitNorm), (float)0.);
            //     return hit.hitSph->sphCol * I;

            //     // img.setPixel(x, y, (hit.hitNorm + Vec(1., 1., 1.))/2.0 );
            // }
            // else
            // {
            //     return Vec(0., 0., 0.);
            // }
        }
        else if (hit.hitSph->sphMat == 1)
        {
            Ray nextRay(hit.hitPos + hit.hitNorm * 0.01, reflect(ray.rayDir, hit.hitNorm));

            return getColor(nextRay, depth+1);
        }
    }
    else
    {
        return Vec(1, 1, 1);
    }
}

int main()
{
    Image img(512, 512);
    Camera cam(Vec(0., 0., -3.), Vec(0., 0., 1.));

    accel.add(std::make_shared<Sphere>(Sphere(1., Vec(0, 0, 1), Vec(1, 0, 0), 0)));
    accel.add(std::make_shared<Sphere>(Sphere(100000., Vec(0, -100001, 0), Vec(1, 1, 1), 0)));

    // Sphere sph(3.0, Vec(0., 0., 3.));
    // Vec lightDir = Vec(-1, 0.5, -1).norm();

#pragma omp parallel for
    for (int i = 0; i < 100; i++)
    {
        for (int y = 1; y <= img.height; y++)
        {
            for (int x = 1; x <= img.width; x++)
            {
                float u = (2.0 * (x + rnd()) - img.width) / img.width;
                float v = (2.0 * (y + rnd()) - img.height) / img.height;
                Ray ray = cam.getRay(u, v);

                color = getColor(ray);
                
                img.setPixel(x, y, img.getPixel(x, y) + color / 100);
            }
        }
    }

    img.gammma_correction();
    img.ppm_output();

    return 0;
}

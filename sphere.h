#ifndef SPHERE_H
#define SPHERE_H

#include "vec.h"
#include "ray.h"
#include "hit.h"

struct Sphere {
	float sphRad;
	Vec sphPos;

	Sphere(float sphRad_, const Vec &sphPos_) : sphRad(sphRad_), sphPos(sphPos_) {};

    bool intersect(const Ray ray, Hit &hit) const {
            float d_norm = (ray.rayDir).abs();
            float oc_norm = (ray.rayPos - sphPos).abs();

            float a = d_norm * d_norm;
            float b = 2 * (ray.rayDir).dot(ray.rayPos - sphPos);
            float c = oc_norm * oc_norm - sphRad * sphRad;
            float D = b*b - 4*a*c;
            if(D < 0) return false;

            float t1 = (-b - std::sqrt(D))/(2*a);
            float t2 = (-b + std::sqrt(D))/(2*a);

            float t = t1;
            if(t < 0) {
                t = t2;
                if(t < 0) return false;
            }

            hit.hitDis = t;
            hit.hitPos = ray.rayPos + ray.rayDir * t;
            hit.hitNorm = (hit.hitPos - sphPos).norm();

            return true;
    }   
};

#endif

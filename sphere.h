#ifndef SPHERE_H
#define SPHERE_H

#include "vec.h"
#include "ray.h"

struct Sphere {
	float rad;
	Vec pos;

	Sphere(float rad_, const Vec &pos_) : rad(rad_), pos(pos_) {};

    bool intersect(const Ray &ray) const {
            float d_norm = (ray.dir).abs();
            float oc_norm = (ray.pos - pos).abs();

            float a = d_norm * d_norm;
            float b = 2 * (ray.dir).dot(ray.pos - pos);
            float c = oc_norm * oc_norm - rad * rad;
            float D = b*b - 4*a*c;
            if(D < 0) return false;

            float t1 = (-b - std::sqrt(D))/(2*a);
            float t2 = (-b + std::sqrt(D))/(2*a);

            if(t1 < 0) {
                if(t2 < 0) return false;
            }

            return true;
        }   
};

#endif

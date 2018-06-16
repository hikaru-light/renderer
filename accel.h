#ifndef ACCEL_H
#define ACCEL_H

#include <vector>
#include <memory>

#include "ray.h"
#include "hit.h"
#include "sphere.h"

struct Accel {
    std::vector<std::shared_ptr<Sphere> > spheres;

    Accel() {};

    void add(std::shared_ptr<Sphere> p) {
        spheres.push_back(p);
    };

    bool intersect(const Ray& ray, Hit& hit) const {
        bool isHit = false;

        hit.hitDis = 1000000000;
        Hit hit_each;

        for(auto p : spheres) {
            if(p->intersect(ray, hit_each)) {
                isHit = true;
                if(hit_each.hitDis < hit.hitDis) {
                    hit = hit_each;
                }
            }
        }

        return isHit;
    };
};

#endif

#ifndef HIT_H
#define HIT_H

#include "vec.h"

struct Hit {
        float hitDis;
        Vec hitPos;
        Vec hitNorm;

        Hit() {};
        Hit(float hitDis_, const Vec &hitPos_, const Vec &hitNorm_) : hitDis(hitDis_), hitPos(hitPos_), hitNorm(hitNorm_) {};
};

#endif

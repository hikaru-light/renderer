#ifndef HIT_H
#define HIT_H
#include "vec.h"

struct Hit {
        float t; //衝突点までの距離
        Vec hitPos; //衝突位置
        Vec hitNorm; //衝突位置の法線

        Hit() {};
        Hit(double t, const Vec &hitPos, const Vec &hitNorm) : t(t), hitPos(hitPos), hitNorm(hitNorm) {};
};

#endif

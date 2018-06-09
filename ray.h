#ifndef RAY_H
#define RAY_H

#include "vec.h"

struct Ray {
	Vec pos;
	Vec dir;

	Ray(const Vec &pos_, const Vec &dir_) : pos(pos_), dir(dir_) {};
};

#endif

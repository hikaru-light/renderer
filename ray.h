#ifndef RAY_H
#define RAY_H

#include "vec.h"

struct Ray {
	Vec rayPos;
	Vec rayDir;

	Ray(const Vec &rayPos_, const Vec &rayDir_) : rayPos(rayPos_), rayDir(rayDir_) {};
};

#endif

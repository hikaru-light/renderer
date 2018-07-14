#ifndef RAY_H
#define RAY_H

struct Ray {
    Vec3 rayOri;
    Vec3 rayDir;

    Ray(const Vec3 rayOri_, const Vec3 rayDir_): rayOri(rayOri_), rayDir(rayDir_) {};
};

#endif

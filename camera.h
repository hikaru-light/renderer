#ifndef CAMERA_H
#define CAMERA_H

#include "vec.h"
#include "ray.h"

struct Camera
{
    Vec camPos;
    Vec camDir;
    Vec camHor;
    Vec camVer;

    Camera(const Vec camPos_, const Vec camDir_) : camPos(camPos_), camDir(camDir_)
    {
        camHor = camDir.cross(Vec(0., 1., 0.)).norm() * -1;
        camVer = camDir.cross(camHor).norm();
    };

    Ray getRay(float u, float v) const
    {
        Vec pinhole = camPos + camDir;
        Vec sensor = camPos + camHor * u + camVer * v;
        return Ray(sensor, (pinhole - sensor).norm());
    };
};

#endif

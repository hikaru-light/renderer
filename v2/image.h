#ifndef IMAGE_H
#define IMAGE_H

#include <ctime>
#include <string>
#include <sstream>

#include "vec.h"

std::string getTimestamp()
{
    std::time_t now = std::time(0);
    std::tm *t = std::localtime(&now);

    std::stringstream tmp;
    tmp
        << 1900 + t->tm_year << "-" << 1 + t->tm_mon << "-" << t->tm_mday
        << " "
        << t->tm_hour << "." << t->tm_min << "." << t->tm_sec;
    return tmp.str();
}

struct Image
{
    int width;
    int height;
    Vec3 *data;

    Image(int width_, int height_) : width(width_), height(height_)
    {
        data = new Vec3[width * height];
    }

    void output_ppm()
    {
        std::string filename = getTimestamp() + ".ppm";
    }
};

#endif

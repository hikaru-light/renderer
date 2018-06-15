#ifndef IMAGE_H
#define IMAGE_H

#include "vec.h"
#include <iostream>
#include <fstream>

struct Image {
    int width;
    int height;
    Vec* data;

    Image(int width_, int height_) {
        width = width_;
        height = height_;
        data = new Vec[width*height];
    };

    ~Image() {
        delete[] data;
    };

    Vec getPixel(int x, int y) const {
        return data[(y-1)*width+(x-1)];
    };

    void setPixel(int x, int y, const Vec &color) {
        data[(y-1)*width+(x-1)] = color;
    };

    void ppm_output() const {
        std::ofstream outputfile("test.ppm");
        outputfile << "P3\n" << width << " " << height << "\n255\n";

        for(int y=1; y<=height; y++) {
            for(int x=1; x<=width; x++) {
                Vec p = this->getPixel(x, y);

                int r = (int)(p.x*255);
                int g = (int)(p.y*255);
                int b = (int)(p.z*255);

                outputfile
                    << r
                    << " "
                    << g
                    << " "
                    << b
                    << "\n";
            }
        }

        outputfile.close();
    };
};

#endif

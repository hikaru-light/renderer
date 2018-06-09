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
        return data[x*y];
    };

    void setPixel(int x, int y, const Vec &color) {
        data[x*y] = color / 255.;
    };

    void ppm_output() const {
        std::ofstream outputfile("test.ppm");
        outputfile << "P3\n" << width << " " << height << "\n255\n";

        for(int x=0; x<height; x++) {
            for(int y=0; y<width; y++) {
                Vec p = this->getPixel(x, y);
                int r = (int)(255*p.x);
                int g = (int)(255*p.y);
                int b = (int)(255*p.z);
                outputfile
                    << r
                    << " "
                    << r
                    << " "
                    << b
                    << "\n";
            }
        }

        outputfile.close();
    };
};

#endif

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
        data[x*y] = color;
    };

    void ppm_output() const {
        std::ofstream outputfile("test.ppm");
        outputfile << "P3\n" << width << " " << height << "\n255\n";

        for(int x=0; x<height; x++) {
            for(int y=0; y<width; y++) {
                Vec p = this->getPixel(x, y);

                int r = (int)(p.x);
                int g = (int)(p.y);
                int b = (int)(p.z);

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

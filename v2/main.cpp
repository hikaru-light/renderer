#include <iostream>

#include "vec.h"
#include "image.h"

int main()
{
    Image img(512, 512);
    img.output_ppm();

    return 0;
}

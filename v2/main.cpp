#include <iostream>

#include "vec.h"

int main()
{
    Vec3 v1 = Vec3(1, 1, 1);
    Vec3 v2 = Vec3(1, 2, 3);

    double a1 = length(v1);
    Vec3 a2 = norm(v1);

    std::cout
        << a1 << std::endl;

    std::cout
        << a2.x << " "
        << a2.y << " "
        << a2.z << std::endl;

    return 0;
}

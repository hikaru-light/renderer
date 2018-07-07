#ifndef VEC_H
#define VEC_H

#include <cmath>

struct Vec3
{
    double x, y, z;

    Vec3(const double x_ = 0, const double y_ = 0, const double z_ = 0) : x(x_), y(y_), z(z_) {};

    inline Vec3 operator+(const Vec3 &b) const
    {
        return Vec3(x + b.x, y + b.y, z + b.z);
    }

    inline Vec3 operator-(const Vec3 &b) const
    {
        return Vec3(x - b.x, y - b.y, z - b.z);
    }

    inline Vec3 operator*(const double &b) const
    {
        return Vec3(x * b, y * b, z * b);
    }

    inline Vec3 operator/(const double &b) const
    {
        return Vec3(x / b, y / b, z / b);
    }
};

inline double length(const Vec3 &b)
{
    return std::sqrt(b.x * b.x + b.y * b.y + b.z * b.z);
}

inline Vec3 norm(const Vec3 &b)
{
    return Vec3(b / length(b));
}

inline double dot(const Vec3 &v1, const Vec3 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2)
{
    return Vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

#endif

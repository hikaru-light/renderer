#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <iostream>

struct Vec
{
	float x, y, z;

	Vec()
	{
		x = y = z = 0;
	};

	Vec(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	};

	Vec operator+(const Vec &b) const
	{
		return Vec(x + (b.x), y + (b.y), z + (b.z));
	};

	Vec operator-(const Vec &b) const
	{
		return Vec(x - (b.x), y - (b.y), z - (b.z));
	};

	Vec operator*(float b) const
	{
		return Vec(x * b, y * b, z * b);
	};

	Vec operator*(Vec b) const
	{
		return Vec(x * b.x, y * b.y, z * b.z);
	};

	Vec operator/(float b) const
	{
		return Vec(x / b, y / b, z / b);
	};

	Vec mult(const Vec &b) const
	{
		return Vec(x * (b.x), y * (b.y), z * (b.z));
	};

	float abs() const
	{
		return sqrt(x * x + y * y + z * z);
	};

	Vec norm()
	{
		return *this = *this * (1 / abs());
	};

	float dot(const Vec &b) const
	{
		return x * (b.x) + y * (b.y) + z * (b.z);
	};

	Vec cross(Vec b)
	{
		return Vec(y * (b.z) - z * (b.y), z * (b.x) - x * (b.z), x * (b.y) - y * (b.x));
	};

	void print() const
	{
		std::cout << "(" << x << ", " << y << ", " << z << ")\n";
	};
};

#endif

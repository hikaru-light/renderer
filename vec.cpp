#include <iostream>
#include <math.h>

struct Vec {
	float x, y, z;

	Vec(float x_, float y_, float z_) {
		x=x_; y=y_; z=z_;
	}

	Vec operator+(const Vec b) const {
		return Vec(x+(b.x), y+(b.y), z+(b.z));
	}

	Vec operator-(const Vec b) const {
		return Vec(x-(b.x), y-(b.y), z-(b.z));
	}

	Vec operator*(float b) const {
		return Vec(x*b, y*b, x*b);
	}

	Vec mult(const Vec b) const {
		return Vec(x*(b.x), y*(b.y), z*(b.z));
	}
	
	float abs() {
		return sqrt(x*x+y*y+z*z);
	}

	Vec norm() {
		return *this = *this * (1/sqrt(x*x+y*y+z*z));
	}

	float dot(const Vec b) const {
		return x*(b.x)+y*(b.y)+z*(b.z);
	}

	Vec cross(Vec b) {
		return Vec(y*(b.z)-z*(b.y), z*(b.x)-x*(b.z), x*(b.y)-y*(b.x));
	}
};

int main(){
	Vec v1(2, 2, 2);
	Vec v2(1, 1, 1);
	
	std::cout << (v1+v2).abs() << "\n";
	std::cout << (v1-v2).abs() << "\n";
	std::cout << (v1*3).abs() << "\n";
	std::cout << v1.mult(v2).abs() << "\n";

	std::cout << v1.dot(v2) << "\n";
	std::cout << v1.cross(v2).abs() << "\n";
	std::cout << v2.norm().abs() << "\n";
}


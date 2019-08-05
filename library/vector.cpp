#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1);

struct vector2 {
	double x, y;
	explicit vector2(double x=0, double y=0): x(x), y(y) {};
	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const { 
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	vector2 operator + (const vector2& rhs) const {
		return vector2(x+rhs.x, y+rhs.y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x-rhs.x, y-rhs.y);
	}
	vector2 operator * (double rhs) const {
		return vector2(x*rhs, y*rhs);
	}
	double magnitude() const {
		return hypot(x, y);
	}
	vector2 unit() const {
		return vector2(x / magnitude(), y / magnitude());
	}
	double polar() const {
		return fmod(atan2(y, x) + 2*PI, 2*PI);
	}
	double dot(const vector2& rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	double cross(const vector2& rhs) const {
		return x*rhs.y - y*rhs.x;
	}
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.unit();
		return r*r.dot(*this);
	}
};

int main() { 

	return 0;
}


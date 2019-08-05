#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1);
const double EPSILON = 1e-6;

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

// perpendicular
bool isVertical(const vector2& A, const vector2& B) {
	return A.dot(B) < EPSILON;
}

double angle(const vector2& A, const vector2& B) {
	return fmod(A.unit().dot(B.unit()) + 2*PI, 2*PI);
}

double isParallel(const vector2& A, const vector2& B) {
	return A.cross(B) < EPSILON;
}

double ccw(const vector2& A, const vector2& B) {
	return A.cross(B);
}
double ccw(const vector2& P, const vector2& A, const vector2& B) {
	return (A-P).cross(B-P);
}



int main() { 

	return 0;
}


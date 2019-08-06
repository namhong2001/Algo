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

double lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
	double det = (b-a).cross(d-c);
	if (fabs(det) < EPSILON) return false;
	x = a + (b-a) * ((c-a).cross(d-c) / det);
	return true;
}

bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (b<a) swap(a, b);
	if (d<c) swap(c, d);
	if (ccw(a, b, c) != 0 || b<c || d<a) return false;
	if (a<c) p=c; else p=a;
	return true;
}

bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
	if (b<a) swap(a, b);
	return p == a || p == b || (a < p && p < b); 
}

bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (!lineIntersection(a, b, c, d, p)) {
		return parallelSegments(a, b, c, d, p);
	}
	return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
} 

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b<c || d<a);
	}
	return ab<=0 && cd<=0;
}

int main() { 

	return 0;
}


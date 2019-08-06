#include <iostream>
#include <iomanip>

using namespace std;

const int PARALLEL = 1;
const int IDENTICAL = -1;
const int INTERSECT = 0; 

struct V {
	double x=0, y=0;
	V () {};
	V (double x, double y): x(x), y(y) {}; 
	V operator + (const V& rhs) {
		return V(x+rhs.x, y+rhs.y);
	}
	V operator - (const V& rhs) {
		return V(x-rhs.x, y-rhs.y);
	}
	V operator * (double m) {
		return V(x*m, y*m);
	}
	double cross (const V& rhs) {
		return x*rhs.y - y*rhs.x;
	}
};

double ccw(V p, V a, V b) {
	return (a-p).cross(b-p);
}

int lineIntersection(V a, V b, V c, V d, V& x) {
	double det = (b-a).cross(d-c);
	if (det == 0) {
		if (ccw(a, b, c) == 0) {
			return IDENTICAL;
		} else {
			return PARALLEL;
		}
	}
	x = a + (b-a)*((c-a).cross(d-c)/det);
	return INTERSECT;
} 

int main() {
	int T;
	cin >> T;
	while (T--) {
		V points[4];
		for (int i=0; i<4; ++i) {
			cin >> points[i].x >> points[i].y;
		}
		V x;
		switch (lineIntersection(points[0], points[1], points[2], points[3], x)) { 
			case PARALLEL:
				cout << "NONE" << '\n';
				break;
			case INTERSECT:
				cout << "POINT" << ' ' << fixed << setprecision(2) << x.x << ' ' << x.y << '\n';
				break;
			case IDENTICAL:
				cout << "LINE" << '\n';
		}
	} 
	return 0;
}


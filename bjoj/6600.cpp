#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = acos(-1);

struct V {
	double x, y;
	V() {};
	V(double x, double y): x(x), y(y) {};
	V operator + (const V& rhs) {
		return V(x+rhs.x, y+rhs.y);
	}
	V operator - (const V& rhs) {
		return V(x-rhs.x, y-rhs.y);
	}
	V operator * (double rhs) {
		return V(x*rhs, y*rhs);
	}
	double magnitude() {
		return hypot(x, y);
	}
	V unit() {
		const double mag = magnitude();
		return V(x/mag, y/mag);
	} 
	double dot(const V& rhs) {
		return x*rhs.x + y*rhs.y;
	} 
	double cross(const V& rhs) {
		return x*rhs.y - y*rhs.x;
	}
	V project(V a, V b) {
		V r = (b-a).unit();
		return a+r*r.dot(*this-a);
	} 
	friend ostream& operator<<(ostream& os, const V& p) {
		os << "{" << p.x << ", " << p.y << "}";
		return os;
	}
};


V perpendicular(V a, V b) {
	V p(12315, 1231512);
	V foot = p.project(a, b);
	return (p-foot).unit();
} 

bool lineIntersection(V a, V b, V c, V d, V& x) {
    double det = (b-a).cross(d-c);
    x = a + (b-a) * ((c-a).cross(d-c) / det);
    return true;
} 
double dist(V a, V b) {
	return hypot(fabs(a.x-b.x), fabs(a.y-b.y));
}

int main() {
	double x1, y1, x2, y2, x3, y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		V a(x1, y1);
		V b(x2, y2);
		V c(x3, y3); 
		V m1 = V((x1+x2)/2, (y1+y2)/2);
		V per1 = perpendicular(a, b);
		V m2 = V((x2+x3)/2, (y2+y3)/2);
		V per2 = perpendicular(b, c);
		V center;
		lineIntersection(m1, m1+per1, m2, m2+per2, center);
		cout << fixed << setprecision(2) << dist(a, center)*2*PI << '\n';
	} 
	return 0;
} 

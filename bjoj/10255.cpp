#include <iostream>

using namespace std;

struct V {
	double x, y;
	explicit V(double x, double y): x(x), y(y) {};
	bool operator == (V rhs) {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (V rhs) {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	V operator - (V rhs) {
		return V(x-rhs.x, y-rhs.y);
	} 
	double cross(V rhs) {
		return x*rhs.y - y*rhs.x;
	}
};


double ccw(V p, V a, V b) {
	return (a-p).cross(b-p);
}

bool segment_intersect(V a, V b, V c, V d) {
	double ab = ccw(a,b,c) * ccw(a,b,d);
	double cd = ccw(c,d,a) * ccw(c,d,b);
	if (ab == 0 && cd == 0) {
		if (b<a) swap(a, b);
		if (d<c) swap(c, d);
		return !(b<c || d<a);
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		double xs[2];
		double ys[2]; 
		for (int i=0; i<2; ++i) {
			cin >> xs[i] >> ys[i];
		}
		double x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2; 
		V a(x1, y1), b(x2, y2);
		const int dx[4] = {-1, 0, 1, 0};
		const int dy[4] = {0, -1, 0, 1};
		int x = 1, y =1;
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			




	
	

	return 0;
}


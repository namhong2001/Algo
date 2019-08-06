#include <iostream> 

using namespace std;

struct V {
	double x, y;
	explicit V(double x, double y): x(x), y(y) {};
	bool operator == (const V& rhs) const {
		return x == rhs.x && y == rhs.y;
	} 
	bool operator < (const V& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	V operator - (const V& rhs) const {
		return V(x-rhs.x, y-rhs.y);
	}
	double cross(const V& rhs) const {
		return x*rhs.y - y*rhs.x;
	} 
};

double ccw(V p, V a, V b) {
	return (a-p).cross(b-p);
} 

bool segmentIntersects(V a, V b, V c, V d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b<a) swap(a, b);
		if (d<c) swap(c, d);
		return !(b<c || d<a);
	}
	return ab<=0 && cd<=0;
} 

bool inBoundingRectangle(V p, V a, V b) {
	if (b<a) swap(a, b); 
	return a.x <= p.x && p.x <= b.x &&
		a.y <= p.y && p.y <= b.y;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		double x, y;
		cin >> x >> y;
		V a(x, y);
		cin >> x >> y;
		V b(x, y);
		double xpos[2];
		double ypos[2];
		for (int i=0; i<2; ++i) {
			cin >> xpos[i] >> ypos[i];
		}
		if (xpos[1] < xpos[0]) swap(xpos[0], xpos[1]);
		if (ypos[1] < ypos[0]) swap(ypos[0], ypos[1]); 
		// counter clockwise
		const int dx[4] = {-1, 0, 1, 0}; 
		const int dy[4] = {0, -1, 0, 1};
		int cx = 1, cy = 1;
		bool ans = false;
		for (int i=0; i<4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i]; 
			ans = ans || segmentIntersects(a, b, V(xpos[cx], ypos[cy]), V(xpos[nx], ypos[ny]));
			cx = nx;
			cy = ny; 
		}
		ans = ans || (inBoundingRectangle(a, V(xpos[0], ypos[0]), V(xpos[1], ypos[1])) 
				&& inBoundingRectangle(b, V(xpos[0], ypos[0]), V(xpos[1], ypos[1])));
		cout << (ans ? "T" : "F") << '\n'; 
	} 
	return 0;
}



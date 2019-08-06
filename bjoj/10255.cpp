#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct V {
	int x=0, y=0; 
	V() {};
	V(int x, int y): x(x), y(y) {};
	V operator + (V rhs) {
		return V(x+rhs.x, y+rhs.y);
	}
	/*
	V operator * (double rhs) {
		return V(x*rhs, y*rhs);
	}
	*/
	bool operator == (V rhs) {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (V rhs) {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	V operator - (V rhs) {
		return V(x-rhs.x, y-rhs.y);
	} 
	int cross(V rhs) {
		return x*rhs.y - y*rhs.x;
	}
};

int ccw(V p, V a, V b) {
	return (a-p).cross(b-p);
}

bool inBoundingRectangle(V p, V a, V b) {
	if (b<a) swap(a, b);
	return p == a || p == b || (a < p && p < b);
}

bool lineIntersection(V a, V b, V c, V d, V& x) {
	int det = (b-a).cross(d-c);
	if (det == 0) return false;
	x = a + (b-a)*((c-a).cross(d-c)/det);
	return true;
} 

int segmentIntersection(V a, V b, V c, V d, V& x) { 
	if (lineIntersection(a, b, c, d, x)) {
		return inBoundingRectangle(x, a, b) && inBoundingRectangle(x, c, d); 
	} else {
		if (ccw(a, b, c)) return 0;
		if (b<a) swap(a, b);
		if (d<c) swap(c, d); 
		if (c == b) { 
			x=c;
			return 1;
		} else if (c < b) {
			return 2;
		} else if (a == d) {
			x=a;
			return 1;
		} else if (a < d) {
			return 2;
		} else {
			return 0;
		}
	}
	return 0;
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
		int cx = 1, cy =1; 
		vector<V> ans;
		bool hasMany = false;
		for (int i=0; i<4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			V p;
			int inter = segmentIntersection(V(xs[cx], ys[cy]), V(xs[nx], ys[ny]), a, b, p);
			if (inter >= 2) {
				hasMany = true;
				cout << 4 << '\n'; 
				break;
			} else if (inter) {
				ans.push_back(p);
			}
			cx = nx;
			cy = ny;
		}
		if (hasMany) continue;
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		cout << ans.size() << '\n';
	} 
	return 0;
} 

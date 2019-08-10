#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct V {
	int x, y;
	V() {};
	V(int x, int y): x(x), y(y) {};
	V operator - (const V& rhs) {
		return V(x-rhs.x, y-rhs.y);
	}
	bool operator < (const V& rhs) {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	int cross (const V& rhs) {
		return x*rhs.y - y*rhs.x;
	} 
};

int ccw(V p, V a, V b) {
	int det = (a-p).cross(b-p);
	if (det > 0) return 1;
	else if (det == 0) return 0;
	else return -1;
}


bool segmentIntersects(V a, V b, V c, V d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b<a) swap(a, b);
		if (d<c) swap(c, d);
		return !(b<c || d<a);
	}
	return ab <=0 && cd <= 0;
}

int main() {
	int N;
	cin >> N;
	vector<V> robots(N);
	vector<V> shelters(N);
	vector<int> perm(N);
	iota(perm.begin(), perm.end(), 0);
	for (int i=0; i<N; ++i) {
		cin >> robots[i].x >> robots[i].y;
	}
	for (int i=0; i<N; ++i) {
		cin >> shelters[i].x >> shelters[i].y;
	}
	do {
		bool intersects = false;
		for (int i=0; i<N; ++i) {
			for (int j=0; j<i; ++j) {
				if (segmentIntersects(robots[i], shelters[perm[i]], robots[j], shelters[perm[j]])) { 
					intersects = true;
					break;
				}
			}
			if (intersects) break;
		}
		if (!intersects) break;
	} while (next_permutation(perm.begin(), perm.end()));
	for (int a : perm) {
		cout << a+1 << '\n';
	} 
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct V {
	int x, y;
	V() {};
	V(int x, int y): x(x), y(y) {};
	bool operator < (const V& rhs) {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	V operator - (const V& rhs) {
		return V(x-rhs.x, y-rhs.y);
	}
	int cross(const V& rhs) {
		return x*rhs.y - y*rhs.x;
	}
};

vector<int> r;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]);
}
void u(int a, int b) {
	a = f(a), b = f(b);
	r[a] = b;
} 

int ccw(V p, V a, V b) {
	int det = (a-p).cross(b-p);
	if (det > 0) return 1;
	else if (det == 0) return 0;
	else return -1;
} 

bool segmentIntersects(V line_1[2], V line_2[2]) {
	V a = line_1[0];
	V b = line_1[1];
	V c = line_2[0];
	V d = line_2[1];
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b<a) swap(a, b);
		if (d<c) swap(c, d);
		return !(b<c || d<a);
	}
	return ab <= 0 && cd <= 0;
} 

int main() {
	int N;
	cin >> N;
	r.resize(N);
	iota(r.begin(), r.end(), 0);
	V lines[N][2];
	for (int i=0; i<N; ++i) {
		cin >> lines[i][0].x >> lines[i][0].y >> lines[i][1].x >> lines[i][1].y;
		for (int j=0; j<i; ++j) {
			if (segmentIntersects(lines[i], lines[j])) {
				u(i, j);
			}
		}
	} 
	int group_cnt = 0;
	int max_segs = 0;
	vector<int> seg_cnt(N, 0);
	for (int i=0; i<N; ++i) {
		seg_cnt[f(i)]++;
	}
	for (int i=0; i<N; ++i) {
		if (seg_cnt[i]) {
			group_cnt++;
			max_segs = max(max_segs, seg_cnt[i]);
		}
	}
	cout << group_cnt << '\n' << max_segs; 
	return 0;
}


#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

const double INF = 1e20;
const double EPSILON = 1e-20;

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
	bool operator == (const V& rhs) {
		return fabs(x-rhs.x) < EPSILON && fabs(y-rhs.y) < EPSILON;
	} 
	bool operator < (const V& rhs) {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	} 
	double magnitude() {
		return hypot(x, y);
	}
	V unit() const {
		double mag = hypot(x, y);
		return V(x/mag, y/mag);
	} 
	double dot (const V& rhs) { 
		return x*rhs.x + y*rhs.y;
	} 
	V project(const V& rhs) const {
		V r = rhs.unit();
		return r*r.dot(*this);
	} 
};

V perpendicularFoot(V p, V a, V b) {
	return a + (p-a).project(b-a);
}

bool inBoundingRectangle(V p, V a, V b) {
	if (b<a) swap(a, b);
	return p == a || p == b || (a < p && p < b);
}

double pointToLine(V p, V a, V b) {
	double ret = INF;
	ret = min(ret, (a-p).magnitude());
	ret = min(ret, (b-p).magnitude());
	V foot = perpendicularFoot(p, a, b);
	if (inBoundingRectangle(foot, a, b)) {
		ret = min(ret, (p-foot).magnitude());
	}
	return ret;
}


double segmentDist(V a, V b, V c, V d) { 
	return min({pointToLine(a, c, d), pointToLine(b, c, d), pointToLine(c, a, b), pointToLine(d, a, b)});
} 

int main() {
	int N, M; 
	cin >> N >> M;
	V A[N][2];
	V B[M][2]; 
	for (int i=0; i<N; ++i) {
		cin >> A[i][0].x >> A[i][0].y >> A[i][1].x >> A[i][1].y;
	}
	for (int i=0; i<M; ++i) {
		cin >> B[i][0].x >> B[i][0].y >> B[i][1].x >> B[i][1].y;
	} 

	double ans = INF;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) { 
			ans = min(ans, segmentDist(A[i][0], A[i][1], B[j][0], B[j][1])); 
		}
	} 
	cout << fixed << setprecision(10) << ans << '\n'; 
	return 0;
}


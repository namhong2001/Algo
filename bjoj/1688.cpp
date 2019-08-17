#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct V {
	ll x, y;
	V() {};
	V(ll x, ll y): x(x), y(y) {};
	V operator - (const V& rhs) {
		return V(x-rhs.x, y-rhs.y);
	}
	bool operator < (const V& rhs) {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	bool operator == (const V& rhs) {
		return x == rhs.x && y == rhs.y;
	}
	ll cross(const V& rhs) {
		return x*rhs.y - y*rhs.x;
	}
};

ll ccw(V p, V a, V b) {
	ll ret = (a-p).cross(b-p);
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

bool onLine(V p, V a, V b) {
	if (ccw(p, a, b) == 0) {
		if (b<a) swap(a, b); 
		return p == a || p == b || (a < p && p < b);
	}
	return false;
}

int isInside(const V& A, const vector<V>& polygon) {
	int N = polygon.size();
	int count = 0;
	for (int i=0; i<N; ++i) {
		int j = (i+1)%N; 
		const V& B = polygon[i];
		const V& C = polygon[j];
		if (onLine(A, B, C)) return 1; 
		if ((A.y > B.y) != (A.y > C.y)) {
			ll dx = C.x - B.x;
			ll dy = C.y - B.y;
			double x = B.x + 1.0*dx/dy*(A.y-B.y);
			if (x > A.x) count++;
		}
	}
	return count % 2; 
} 
			
int main() {
	int N;
	cin >> N;
	vector<V> polygon(N);
	for (int i=0; i<N; ++i) {
		cin >> polygon[i].x >> polygon[i].y;
	}
	for (int i=0; i<3; ++i) {
		V A;
		cin >> A.x >> A.y;
		cout << isInside(A, polygon) << '\n';
	} 
	return 0;
}


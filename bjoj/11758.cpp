#include <iostream>

using namespace std;

struct V {
	double x=0, y=0; 
	V operator - (const V& rhs) const {
		return V {x-rhs.x, y-rhs.y};
	}
	double cross(const V& rhs) const {
		return x*rhs.y - y*rhs.x;
	}
};

double ccw(const V& P, const V& A, const V& B) {
	return (A-P).cross(B-P);
}

int main() {
	V in[3];
	for (int i=0; i<3; ++i) {
		cin >> in[i].x >> in[i].y;
	}
	double ans = ccw(in[0], in[1], in[2]);
	if(ans > 0) cout << 1;
	else if (ans < 0) cout << -1;
	else cout << 0; 
	return 0;
}


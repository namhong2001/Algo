#include <iostream>
#include <cmath>

using namespace std;

struct Circle {
	int x, y, r;
	bool operator == (const Circle& rhs) {
		return x == rhs.x && y == rhs.y && r == rhs.r;
	}
};

double dist(Circle A, Circle B) {
	return hypot(abs(A.x-B.x), abs(A.y-B.y));
} 

int main() {
	int T;
	cin >> T;
	while (T--) {
		Circle A, B;
		cin >> A.x >> A.y >> A.r;
		cin >> B.x >> B.y >> B.r;
		const double d = dist(A, B); 
		if (A == B) cout << -1 << '\n'; 
		else if (d > A.r + B.r) {
			cout << 0 << '\n';
		} else if (d == A.r + B.r) {
			cout << 1 << '\n';
		} else {
			int maxr = max(A.r, B.r);
			int minr = min(A.r, B.r); 
			if (maxr == d + minr) {
				cout << 1 << '\n';
			} else if (maxr > d + minr) {
				cout << 0 << '\n';
			} else {
				cout << 2 << '\n';
			}
		}
	} 
	return 0;
}


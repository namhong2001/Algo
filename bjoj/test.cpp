#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

typedef long double ld;

const ld PI = acos(-1);

ld L, N, C;
ld L2;

bool decision(double rad) {
	ld rad2 = rad/2;
	ld r = L/2/sin(rad2);
	ld arc = r*rad;
	return arc <= L2;
} 

int main() {
	while (true) {
		cin >> L >> N >> C;
		if (L < 0) break;
		L2 = (1.0+N*C)*L;
		ld l = 0, r = PI;
		for (int i=0; i<1000; ++i) {
			ld mid = (l+r)/2;
			if (decision(mid)) {
				l = mid;
			} else {
				r = mid;
			}
		} 
		cerr << l << endl;
		ld radius = L/2/sin(l/2);
		cerr << radius << endl;
		ld ans = radius - radius*cos(l/2);
		cerr << ans << endl;
		cout << fixed << setprecision(3) << ans << '\n';
	}
	return 0;
} 


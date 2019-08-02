#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

typedef long double ld;

const ld PI = acos(-1);

ld L, N, C;
ld L2;

bool decision(ld rad) {
	ld rad2 = rad/2;
	ld r = L/2/sinl(rad2);
	ld arc = r*rad;
	return arc <= L2;
} 

int main() {
	while (true) {
		cin >> L >> N >> C;
		if (L < 0) break;
		L2 = (1.0l+N*C)*L;
		ld l = 0, r = PI;
		for (int i=0; i<1000; ++i) {
			ld mid = (l+r)/2;
			if (decision(mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		ld rad = (l+r)/2; 
		ld radius = L/2/sinl(rad/2);
		ld ans = radius - radius*cosl(rad/2);
		cout << fixed << setprecision(3) << ans << '\n';
	}
	return 0;
} 

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

const double PI = acos(-1);

double L, N, C;
double L2;

bool decision(double rad) {
	double rad2 = rad/2;
	double r = L/2/sin(rad2);
	double arc = r*rad;
	return arc <= L2;
} 

int main() {
	while (true) {
		cin >> L >> N >> C;
		if (L < 0) break;
		L2 = (1.0+N*C)*L;
		double l = 0, r = PI;
		for (int i=0; i<100; ++i) {
			double mid = (l+r)/2;
			if (decision(mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		double radius = L/2/sin(l/2);
		double ans = radius - radius*cos(l/2);
		cout << fixed << setprecision(3) << ans << '\n';
	}
	return 0;
} 

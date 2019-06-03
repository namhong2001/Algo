#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double x, y, c;
	cin >> x >> y >> c;
	double l = 0, r = min(x, y);
	while (r-l >= 1e-6) {
		double mid = (l+r)/2;
		double xh = sqrt(x*x-mid*mid);
		double yh = sqrt(y*y-mid*mid);
		double ec = xh*yh/(xh+yh);
		if (ec < c) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(6) << l << endl;
	return 0;
} 

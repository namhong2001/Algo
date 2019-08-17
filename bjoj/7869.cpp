#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

const double PI = acos(-1);
const double EPSILON = 1e-9;

int main() {
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2; 
	double d = hypot(x1-x2, y1-y2);
	if (r1+r2 <= d) {
		cout << fixed << setprecision(3) << 0.0 << endl;
		return 0;
	}
	if (fabs(r1-r2) >= d) { 
		double m = min(r1, r2);
		cout << fixed << setprecision(3) << m*m*PI << endl;
		return 0;
	}
	double s = (r1 + r2 + d)/2;
	double S = sqrt(s*(s-r1)*(s-r2)*(s-d)); 
	double a1 = acos((d*d+r1*r1-r2*r2)/(2*d*r1));
	double a2 = acos((d*d+r2*r2-r1*r1)/(2*d*r2));
	double ans = r1*r1*a1 + r2*r2*a2 - S*2;
	cout << fixed << setprecision(3) << ans << endl; 
	return 0;
}


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = acos(-1);

int main() {
	double x1, y1, x2, y2, x3, y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		double d1 = (x2-x1)/(y2-y1);
		double d2 = (x3-x2)/(y3-y2);
		double cx = ((y3-y1)+(x2+x3)*d2-(x1+x2)*d1)/(2*(d2-d1));
		double cy = -d1*(cx-(x1+x2)/2)+(y1+y2)/2;
		double r = hypot(x1-cx, y1-cy);
		cout << fixed << setprecision(2) << 2*PI*r << '\n'; 
	} 
	return 0;
} 

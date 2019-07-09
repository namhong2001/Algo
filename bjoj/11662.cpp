#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int A[2][2];
int B[2][2];

double dist(double t) {
	double ax = (A[1][0] - A[0][0]) * t + A[0][0];
	double bx = (B[1][0] - B[0][0]) * t + B[0][0];
	double ay = (A[1][1] - A[0][1]) * t + A[0][1];
	double by = (B[1][1] - B[0][1]) * t + B[0][1];
	return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
} 

int main() {
	for (int i=0; i<2; ++i) {
		for (int j=0; j<2; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i=0; i<2; ++i) {
		for (int j=0; j<2; ++j) {
			cin >> B[i][j];
		}
	}
	double l = 0, r = 1;
	for (int i=0; i<100; ++i) {
		double a = (2*l+r)/3;
		double b = (l+2*r)/3;
		if (dist(a) > dist(b)) {
			l = a;
		} else {
			r = b;
		}
	}
	cout << fixed << setprecision(10) << sqrt(dist(l)) << endl;
} 

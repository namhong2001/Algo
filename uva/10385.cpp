#include <iostream>
#include <vector> 
#include <iomanip>

using namespace std;

vector<double> A;
vector<double> B;
double t;
int n;

double f(double x, double a, double b) {
	return x/a + (t-x)/b;
} 

double diff(double x) {
	double m = f(x, A[0], B[0]);
	for (int i=1; i<n-1; ++i) {
		m = min(m, f(x, A[i], B[i]));
	}
	double me = f(x, A[n-1], B[n-1]);
	return m - me;
}

int main() {
	while (cin >> t) {
		cin >> n;
		A.resize(n);
		B.resize(n);
		for (int i=0; i<n; ++i) {
			cin >> A[i] >> B[i];
		}
		double l = 0, r = t;
		for (int i=0; i<100; ++i) {
			double a = (2*l + r)/3;
			double b = (l + 2*r)/3; 
			if (diff(a) < diff(b)) {
				l = a;
			} else {
				r = b;
			} 
		}
		double ans = diff(l);
		
		if (ans < 0) {
			cout << "The cheater cannot win." << '\n';
		} else {
			cout << fixed << setprecision(0) << "The cheater can win by " << 
				ans*60*60 << " seconds with r = " <<
				setprecision(2) << l << "km and k = " << t-l << "km." << '\n';
		}
	}
	return 0;
} 

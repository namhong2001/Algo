#include <iostream>
#include <iomanip>

using namespace std;


double N, P;
int M;

bool decision(double C) {
	double remain = N;
	for (int i=0; i<M; ++i) {
		remain = remain*(1.0 + P/12/100)-C;
		if (remain <= 0) return true;
	}
	return false;
} 

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M >> P; 
		double l = 0, r = 2e8;
		for (int i=0; i<100; ++i) {
			double mid = (l+r)/2;
			if (decision(mid)) r = mid;
			else l = mid;
		}
		cout << fixed << setprecision(10) << r << '\n';
	}
	return 0;
} 

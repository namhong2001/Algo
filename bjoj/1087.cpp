#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef pair<int,int> pii;

vector<pii> X;
vector<pii> Y;

double at(double t, pii &func) {
	return func.first + func.second * t;
}

double dist(double t, vector<pii> &funcs) {
	double mmax = at(t, funcs[0]);
	double mmin = at(t, funcs[0]);
	for (pii &func : funcs) {
		mmax = max(mmax, at(t, func));
		mmin = min(mmin, at(t, func));
	}
	return mmax - mmin;
}

double L(double t) {
	return max(dist(t, X), dist (t, Y));
} 

int main() {
	int N;
	cin >> N;
	for (int i=0; i<N; ++i) {
		int px, py, vx, vy;
		cin >> px >> py >> vx >> vy;
		X.push_back({px, vx});
		Y.push_back({py, vy});
	}
	double l = 0, r = 10000;
	for (int i=0; i<1000; ++i) {
		double a = (2*l + r) / 3;
		double b = (l + 2*r) / 3;
		if (L(a) > L(b)) {
			l = a;
		} else {
			r = b;
		} 
	}
	cout << fixed << setprecision(10) << L((l+r)/2)	<< endl;
	return 0;
} 

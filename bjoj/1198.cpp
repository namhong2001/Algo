#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double size(double x1, double y1, double x2, double y2, double x3, double y3) {
	return fabs(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3)/2;
}


int main() {
	int N;
	cin >> N;
	vector<int> X(N);
	vector<int> Y(N);
	for (int i=0; i<N; ++i) {
		cin >> X[i] >> Y[i];
	}
	X.push_back(X[0]);
	X.push_back(X[1]);
	Y.push_back(Y[0]); 
	Y.push_back(Y[1]); 
	double ans = 0;
	for (int i=0; i<(int)X.size()-2; ++i) {
		for (int j=i+1; j<(int)X.size()-2; ++j) {
			for (int k=j+1; k<(int)X.size()-2; ++k) { 
				ans = max(ans, size(X[i], Y[i], X[j], Y[j], X[k], Y[k]));
			}
		}
	} 
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}


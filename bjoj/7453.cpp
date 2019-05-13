#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(n);
	vector<int> D(n);
	for (int i=0; i<n; ++i) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	vector<int> AB(n*n);
	vector<int> CD(n*n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			AB[n*i+j] = A[i] + B[j];
			CD[n*i+j] = C[i] + D[j];
		}
	}
	sort(CD.begin(), CD.end());
	ll ans = 0;
	for (int i=0; i<n*n; ++i) {
		auto lower = lower_bound(CD.begin(), CD.end(), -AB[i]);
		auto upper = upper_bound(CD.begin(), CD.end(), -AB[i]);
		ans += distance(lower, upper);
	}
	cout << ans;
	return 0;
} 

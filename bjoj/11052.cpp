#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> P;
int d[1001];
int solve(int n) {
	if (n == 0) return 0;
	if (n == 1) return P[1];
	if (d[n]) return d[n];
	int &ret = d[n];
	for (int i=1; i<=n; ++i) {
		ret = max(ret, P[i] + solve(n-i));
	}
	return ret;
} 

int main() {
	cin >> N;
	P.assign(N+1, 0);
	for (int i=1; i<=N; ++i) {
		cin >> P[i];
	}
	cout << solve(N) << endl; 
	return 0;
}


#include <iostream>
#include <cmath>

using namespace std;

const int INF = 987654321;

int d[100001];
int solve(int n) {
	if (n==0) return 0;
	if (d[n]) return d[n];
	int &ret = d[n];
	ret = INF;
	for (int i=1; i*i<=n; ++i) {
		ret = min(ret, 1+solve(n-i*i));
	}
	return ret;
} 

int main() {
	int N;
	cin >> N;
	cout << solve(N) << endl; 
	return 0;
}


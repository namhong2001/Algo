#include <iostream>
#include <cstring>

using namespace std;

int d[31];
int solve(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 3;
	int &ret = d[n];
	if (ret != -1) return ret;
	return ret = solve(n-2)*2 + solve(n-1);
} 

int main() {
	memset(d, -1, sizeof(d));
	int N;
	cin >> N;
	int ans;
	if (N == 1) {
		ans = 1;
	} else if (N == 2) {
		ans = 3;
	} else if (N%2) {
		ans = solve(N) + solve(N/2);
		ans /= 2; 
	} else {
		ans = solve(N) + solve(N/2) + 2*solve((N-2)/2);
		ans /= 2;
	}
	cout << ans;
	return 0;
}


#include <iostream>

using namespace std;

typedef long long ll;

ll d[2][100];
ll solve(int pre, int remain) {
	if (remain == 0) return 1ll;
	if (d[pre][remain]) return d[pre][remain]; 

	ll &ret = d[pre][remain]; 
	if (pre == 1) {
		return ret = solve(0, remain-1);
	} else {
		return ret = solve(0, remain-1) + solve(1, remain-1);
	}
}

int main() {
	int N;
	cin >> N;
	cout << solve(1, N-1) << endl; 
	return 0;
}


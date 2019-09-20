#include <iostream>
#include <cstring>

using namespace std;

int ans = 0;
int cnt = 0;

int board[11];
int d[11][1<<10]; 

int solve(int ith, int can_use) { 
	if (ith == 0) return 0;
	int &ret = d[ith][can_use];
	if (ret != -1) return ret;
	for (int i=0; i<1<<10; ++i) {
		int cur = i & can_use & board[i]; 
		ret = max(ret, __builtin_popcount(cur) + solve(ith-1, ~(state << 1 | state >> 1) & can_use);
}
	
int main() {
	int N;
	cin >> N;
	for (int i=1; i<=N; ++i) {
		int state = 0;
		for (int j=0; j<N; ++j) {
			int a;
			cin >> a;
			state <<= 1;
			state |= a;
		}
		board[i] = state;
	}
	memset(d, -1, sizeof(d));
	int ans = 0;
	for (int state=0; state<1<<N; ++state) {
		ans = max(ans, solve(N, state & board[N]));
	}
	cout << ans;
	return 0;
}


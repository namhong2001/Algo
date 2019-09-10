#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int T, N;
	cin >> T >> N;
	int d[T+1] = {};
	int step[N+1][T+1] = {};
	int rest[N+1] = {};
	for (int i=1; i<=N; ++i) {
		cin >> rest[i];
		for (int j=T; j>=rest[i]; --j) {
			if (d[j] < d[j-rest[i]] + rest[i]) {
				d[j] = d[j-rest[i]] + rest[i];
				step[i][j] = i;
			}
		}
	}
	int ans[N+1] = {};
	memset(ans, -1, sizeof(ans)); 
	for (int i=N, w=T; i>=1; --i) {
		if (step[i][w]) {
			int here = step[i][w];
			w-=rest[here];
			ans[here] = w;
		}
	}
	for (int i=1, w=0; i<=N; ++i) {
		if (ans[i] == -1) {
			ans[i] = w;
			w += rest[i];
		}
	}
	for (int i=1; i<=N; ++i) cout << ans[i] << ' '; 
	return 0;
}


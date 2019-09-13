#include <iostream>
#include <cstring>

using namespace std; 

int main() {
	int N, K;
	cin >> N >> K;
	int walk_c[N+1];
	int walk_v[N+1];
	int cycle_c[N+1];
	int cycle_v[N+1];
	for (int i=1; i<=N; ++i) {
		cin >> walk_c[i];
		cin >> walk_v[i];
		cin >> cycle_c[i];
		cin >> cycle_v[i];
	}
	int d[K+1] = {};
	memset(d, -1, sizeof(d));
	d[0] = 0;
	for (int i=1; i<=N; ++i) {
		for (int j=K; j>=0; --j) { 
			int val = -1;
			if (j-walk_c[i] >= 0 && d[j-walk_c[i]] != -1) val = max(val, d[j-walk_c[i]] + walk_v[i]);
			if (j-cycle_c[i] >= 0 && d[j-cycle_c[i]] != -1) val = max(val, d[j-cycle_c[i]] + cycle_v[i]);
			d[j] = val;
		}
	}
	int ans = 0;
	for (int i=K; i>=0; --i) {
		ans = max(ans, d[i]);
	}
	cout << ans;
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T; 
	while (T--) {
		int L, N;
		cin >> L >> N;
		vector<int> loc(N);
		for (int i=0; i<N; ++i) {
			cin >> loc[i];
		}
		sort(loc.begin(), loc.end());
		int minans = 0;
		int maxans = 0;
		for (int i=0; i<N; ++i) {
			minans = max(minans, min(loc[i], L-loc[i]));
			maxans = max(maxans, max(loc[i], L-loc[i]));
		} 
		cout << minans << ' ' << maxans << '\n';
	}
	return 0;
} 

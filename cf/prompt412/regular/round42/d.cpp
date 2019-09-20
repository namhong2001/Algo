#include <iostream>
#include <vector>
#include <limits>
#include <iterator>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<int> cities(N);
	vector<int> towers(M);
	for (int i=0; i<N; ++i) {
		cin >> cities[i];
	} 
	for (int i=0; i<M; ++i) {
		cin >> towers[i];
	}
	int ans = -1;
	for (int i=0; i<N; ++i) {
		int here = cities[i];
		auto lower = lower_bound(towers.begin(), towers.end(), here);
		int r = INF; 
		if (lower != towers.begin()) {
			auto left = prev(lower); 
			r = min(r, abs(here-*left));
		}
		if (lower != towers.end()) {
			r = min(r, abs(here-*lower));
		}
		ans = max(ans, r);
	}
	cout << ans << endl; 
	return 0;
}

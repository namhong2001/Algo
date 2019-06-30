#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> L(N);
		vector<int> M(N);
		vector<int> G(N);
		for (int i=0; i<N; ++i) {
			cin >> L[i] >> M[i] >> G[i];
		}
		auto get_cnt = [&](int pos) {
			ll cnt = 0;
			for (int i=0; i<N; ++i) {
				int start = L[i] - M[i];
				if (start <= pos) {
					int dist = min(pos, L[i]) - start;
					cnt += dist/G[i] + 1;
				}
			}
			return cnt;
		};
		ll l = 0, r = (1ll<<31)-1;
		while (l<r) {
			ll mid = (l+r)/2;
			ll cnt = get_cnt(mid);
			if (cnt < K) l = mid+1;
			else r = mid;
		}
		cout << l << '\n';
	}
	return 0;
} 

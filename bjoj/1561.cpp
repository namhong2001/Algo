#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int N, M;
	cin >> N >> M;
	vector<ll> time(M);
	for (int i=0; i<M; ++i) {
		cin >> time[i];
	}
	auto get_cnt = [&](ll limit) {
		if (limit < 0) return 0ll;
		ll cnt = 0;
		for (ll t : time) {
			cnt += (limit)/t + 1;
		}
		return cnt;
	};
	ll l = 0, r = 6e10+1;
	while (l < r) {
		ll mid = (l+r)/2;
		if (get_cnt(mid) < N) l = mid+1;
		else r = mid;
	}
	ll remain = N - get_cnt(l-1); 
	for (int i=0; i<M; ++i) {
		int t = time[i];
		if (l % t == 0) {
			remain--;
			if (remain == 0) {
				cout << i+1 << endl;
				return 0; 
			}
		}
	}
	return 0; 
} 

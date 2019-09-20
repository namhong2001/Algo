#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

const int N_MAX = 1e5;
const int MOD = 5e6;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K;
	cin >> N >> K;
	vector<int> M;
	vector<int> cnt(N_MAX+1);
	cnt[0] = 1;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		auto lower = lower_bound(M.begin(), M.end(), a);
		if (lower != M.end()) {
			*lower = a;
			int pos = lower-M.begin()+1;
			cnt[pos] += cnt[pos-1];
			cnt[pos] %= MOD; 
		} else {
			M.push_back(a);
			int pos = M.size();
			cnt[pos] += cnt[pos-1];
			cnt[pos] %= MOD; 
		}
	}
	cout << cnt[K]; 
	return 0;
}


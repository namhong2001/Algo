#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std; 

int solve1(vector<int> &remains_cnt) {
	const int MOD = 20091101;
	int ret = 0;
	for (int i=0; i<remains_cnt.size(); ++i) {
		int cnt = remains_cnt[i];
		if (i==0) ret += 1ll*cnt*(cnt+1)/2%MOD;
		else ret += 1ll*cnt*(cnt-1)/2%MOD;
		ret %= MOD;
	}
	return ret;
} 

int solve2(vector<int> &left_pair, int n) {
	vector<int> d(n, -1);
	function<int(int)> dp = [&](const int &here) {
		if (here < 0) return 0;
		int &ret = d[here];
		if (ret != -1) return ret;
		int lp = left_pair[here];
		if (lp == -1) return ret = dp(here-1);
		else return ret = max(dp(lp)+1, dp(here-1));
	};
	return dp(n-1);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> dolls(n);
		for (int i=0; i<n; ++i) {
			cin >> dolls[i];
		}
		vector<int> psum(n);
		vector<int> remains_cnt(k, 0);
		psum[0] = dolls[0] % k;
		remains_cnt[psum[0]]++; 
		for (int i=1; i<n; ++i) {
			psum[i] = (psum[i-1] + dolls[i]) % k; 
			remains_cnt[psum[i]]++; 
		}
		vector<int> left_pair(n, -1);
		vector<int> discovered(k, -1);
		for (int i=0; i<n; ++i) {
			int r = psum[i]; 
			if (r == 0 && discovered[r] == -1) {
				left_pair[i] = -2;
			}
			if (discovered[r] != -1) {
				left_pair[i] = discovered[r];
			}
			discovered[r] = i;
		} 
		cout << solve1(remains_cnt) << ' ' << solve2(left_pair, n) << endl; 
	}
	return 0;
} 

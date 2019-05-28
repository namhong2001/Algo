#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k; 
	vector<int> same_len[21];
	for (int i=1; i<=n; ++i) {
		string s;
		cin >> s;
		same_len[s.size()].push_back(i);
	}
	ll ans = 0;
	for (int i=2; i<21; ++i) {
		vector<int> &sl = same_len[i]; 
		for (int here = 0; here < sl.size(); ++here) { 
			auto lower = lower_bound(sl.begin(), sl.end(), sl[here]-k);
			auto upper = upper_bound(sl.begin(), sl.end(), sl[here]+k);
			int cnt = distance(lower, upper);
			ans += cnt-1;
		}
	}
	cout << ans/2 << endl;
	return 0;
} 

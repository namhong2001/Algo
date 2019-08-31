#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map<int,ll> ans;

void solve(string &S) {
	int N = S.size();
	int Z[N] = {};
	int L = 0, R = 0;
	for (int i=1; i<N; ++i) {
		if (i>R) {
			L = R = i;
			while (R < N && S[R-L] == S[R]) R++;
			Z[i] = R-L;
			R--;
		} else {
			if (Z[i-L] < R-i+1) Z[i] = Z[i-L];
			else {
				L = i;
				while (R < N && S[R-L] == S[R]) R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
	ll total = 0;
	for (int i=N-1; i>0; --i) { 
		int len = Z[i];
		if (len > 0) {
			if (Z[N-len] == len) {
				ans[len]++;
				total++;
			} else { 
				if (!ans.empty()) { 
					auto upper = ans.upper_bound(len);
					if (upper != ans.begin()) {
						(prev(upper)->second)++;
						total++;
					} 
				}
			} 
		}
	}
	ans[N]++;
	total++;

	cout << ans.size() << '\n';
	for (auto a : ans) {
		cout << a.first << ' ' << total << '\n';
		total -= a.second;
	} 
}

int main() {
	string S;
	cin >> S;
	solve(S);
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> cows[3];
	for (int i=1; i<=n; ++i) {
		int type;
		cin >> type;
		type--;
		cows[type].push_back(i);
	}
	for (int iter=0; iter<q; ++iter) {
		int s, e;
		cin >> s >> e;
		for (int i=0; i<3; ++i) {
			auto lower = lower_bound(cows[i].begin(), cows[i].end(), s);
			auto upper = upper_bound(cows[i].begin(), cows[i].end(), e);
			cout << distance(lower, upper) << ' ';
		}
		cout << '\n';
	}
	return 0;
} 

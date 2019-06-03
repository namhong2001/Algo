#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int main() {
	int n;
	cin >> n;
	vector<pii> load(n);
	for (int i=0; i<n; ++i) {
		cin >> load[i].second >> load[i].first;
	}
	sort(load.begin(), load.end(), greater<pii>());
	vector<bool> used(1001, false);
	int ans = 0;
	for (pii &l : load) { 
		for (int i=l.second; i>0; --i) {
			if (!used[i]) {
				used[i] = true;
				ans += l.first;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
} 

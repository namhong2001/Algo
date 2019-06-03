#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int l, n, rf, rb;
	cin >> l >> n >> rf >> rb;
	vector<pii> rest(n); 
	for (int i=0; i<n; ++i) {
		cin >> rest[i].second >> rest[i].first;
	}
	sort(rest.begin(), rest.end(), greater<pii>());
	int end = 0;
	ll ans = 0;
	for (pii &r : rest) {
		if (r.second <= end) continue;
		int dist = r.second - end;
		ans += 1ll*r.first*dist*(rf-rb);
		end = r.second;
	}
	cout << ans << endl;
	return 0;
} 

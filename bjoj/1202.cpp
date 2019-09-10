#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, K;
	cin >> N >> K;
	vector<pii> jewels(N);
	for (int i=0; i<N; ++i) cin >> jewels[i].second >> jewels[i].first;
	sort(jewels.begin(), jewels.end(), greater<pii>()); 
	multiset<int> knapsacks; 
	for (int i=0; i<K; ++i) {
		int c;
		cin >> c;
		knapsacks.insert(c);
	}
	ll ans = 0;
	for (int i=0; i<N; ++i) {
		int v = jewels[i].first;
		int w = jewels[i].second;
		auto lower = knapsacks.lower_bound(w);
		if (lower != knapsacks.end()) {
			ans += v;
			knapsacks.erase(lower);
		}
	}
	cout << ans; 
	return 0;
}


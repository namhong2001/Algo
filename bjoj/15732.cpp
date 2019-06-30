#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> Rule;
typedef long long ll;


int main() {
	ll N, K, D;
	cin >> N >> K >> D;
	vector<Rule> rules(K);
	for (int i=0; i<K; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		rules[i] = {a, b, c};
	}
	auto get_cnt = [&](int pos) {
		ll cnt = 0 ;
		for (Rule &r : rules) {
			int a, b, c;
			tie(a, b, c) = r;
			int range = min(pos, b) - a;
			if (range >= 0) {
				cnt += range/c + 1;
			}
		}
		return cnt;
	};
	int l = 0, r = 1e6;
	while (l<r) {
		int mid = (l+r)/2;
		if (get_cnt(mid) < D) l = mid+1;
		else r = mid;
	}
	cout << l << endl;
	return 0;
} 

#include <iostream>

using namespace std;

typedef long long ll;

const ll LIMIT = (ll)2e9+1;

ll N, M;
ll Z;
bool decision(ll mid) {
	return (M+mid)*100/(N+mid) > Z;
} 

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		Z = M*100/N;
		if (Z >= 99) {
			cout << -1 << '\n';
			continue;
		}
		ll l = 0, r = (ll)2e9;
		while (l<r) {
			ll mid = (l+r)/2;
			if (decision(mid)) r = mid;
			else l = mid+1;
		}
		cout << l << '\n';
	}
	return 0;
} 

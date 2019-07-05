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
		ll l = 0, r = LIMIT;
		while (l+1<r) {
			ll mid = (l+r)/2;
			if (decision(mid)) r = mid;
			else l = mid;
		}
		if (r == LIMIT) cout << -1 << '\n';
		else cout << r << '\n';
	}
	return 0;
} 

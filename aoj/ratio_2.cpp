#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll N, M;
		cin >> N >> M;
		ll Z = M*100/N+1;
		if (Z >= 100) {
			cout << -1 << '\n';
			continue;
		}
		ll ans = (Z*N-100*M-1)/(100-Z)+1;
		cout << ans << '\n';
	}
	return 0;
} 

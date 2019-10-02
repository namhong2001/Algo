#include <iostream>

using namespace std;

typedef long long ll;

const ll LIMIT = 1e6+1;

bool in_sequence(ll num, ll N, ll F, ll D) {
	return num-F >= 0 && (num-F)%D == 0 && (num-F)/D < N;
} 

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll N1, F1, D1, N2, F2, D2;
		cin >> N1 >> F1 >> D1 >> N2 >> F2 >> D2; 
		int ans = 0;
		for (ll i=1; i<LIMIT; ++i) {
			ans += in_sequence(i, N1, F1, D1) && in_sequence(i, N2, F2, D2);
		}
		cout << ans << '\n';
	} 
	return 0;
}


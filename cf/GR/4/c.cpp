#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main() {
	int W, H;
	cin >> W >> H;
	int cnt_2 = W-1 + H-1;
	ll ans = 4;
	for (int i=0; i<cnt_2; ++i) {
		ans *= 2;
		ans %= MOD;
	}
	cout << ans << endl; 
	return 0;
}

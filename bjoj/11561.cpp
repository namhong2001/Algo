#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		ll num;
		cin >> num;
		num *= 2;
		ll ans = floorl(sqrtl(num));
		if (ans*(ans+1) > num) ans--;
		cout << ans << '\n';
	}
	return 0;
}

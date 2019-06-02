#include <iostream>

using namespace std;

int main() {
	for (int t=1; ; ++t) { 
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;
		int cnt = v/p;
		int ans = l*cnt + min(l, v%p);
		cout << "Case " << t << ": " << ans << '\n';
	}
	return 0;
} 

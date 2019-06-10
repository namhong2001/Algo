#include <iostream>

using namespace std;

typedef long long ll;


ll d[11];

ll solve(int n) {
	if (n==0) return 0;
	if (n==1) return 1;
	if (n==2) return 2; 
	if (n==3) return 4;
	ll &ret = d[n];
	if (ret != 0) return ret; 
	for (int i=1; i<min(n, 4); ++i) {
		ret += solve(n-i);
	}
	return ret;
} 

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		ll ans = solve(n);
		cout << ans << endl;
	}
	return 0;
} 

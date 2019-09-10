#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;
	int minuscnt = 0;
	int zerocnt = 0; 
	ll ans = 0;
	for (int i=0; i<N; ++i) {
		int a;
		cin >> a;
		if (a < 0) {
			minuscnt++;
			ans += abs(a)-1;
		} else if (a > 0)  {
			ans += abs(a)-1;
		} else {
			ans++;
			zerocnt++;
		}
	}
	if (minuscnt % 2) {
		if (zerocnt == 0) ans += 2;
	}
	cout << ans; 
	return 0;
}


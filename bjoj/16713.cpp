#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned int ui;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	ui psum[n+1]; 
	memset(psum, 0, sizeof(psum));
	for (int i=1; i<=n; ++i) {
		ui a;
		cin >> a;
		psum[i] = psum[i-1]^a;
	}
	ui ans = 0;
	for (int i=0; i<q; ++i) {
		int s, e;
		cin >> s >> e; 
		ans ^= psum[e];
		ans ^= psum[s-1];
	}
	cout << ans << endl;
	return 0;
} 

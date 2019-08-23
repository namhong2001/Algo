#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	string ans;
	while (N) {
		int r = N % -2; 
		N /= -2;
		if (r < 0) {
			r += 2;
			N += 1;
		}
		ans += '0' + r;
	}
	if (ans.empty()) {
		ans = "0";
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl; 
	return 0;
}


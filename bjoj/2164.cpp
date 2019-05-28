#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int m = 1;
	while (m <= n) m<<=1;
	int ans = ~m & (n<<1 | 1);
	ans--;
	if (ans == 0) ans = n;
	cout << ans;
	return 0;
} 

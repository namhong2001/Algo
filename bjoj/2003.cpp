#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int input[n];
	int sum = 0;
	int left = 0;
	int ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> input[i];
		sum += input[i];
		while (sum > m && left <= i) {
			sum -= input[left];
			left++;
		} 
		if (sum == m) ans++;
	}
	cout << ans;
	return 0;
}

#include <iostream>

using namespace std;

const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, s;
	cin >> n >> s;
	int input[n];
	int sum = 0;
	int left = 0;
	int ans = INF;
	for (int i=0; i<n; ++i) {
		cin >> input[i];
		sum += input[i];
		while (sum >= s && left <= i) {
			ans = min(ans, i-left+1);
			sum -= input[left++]; 
		}
	} 
	if (ans == INF) ans=0;
	cout << ans;
	return 0;
} 

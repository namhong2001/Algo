#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> weight(n);
	for (int i=0; i<n; ++i) {
		cin >> weight[i];
	}
	sort(weight.begin(), weight.end(), greater<int>());
	int ans = 0;
	for (int i=0; i<n; ++i) {
		ans = max(ans, weight[i]*(i+1));
	}
	cout << ans << endl;
	return 0;
}




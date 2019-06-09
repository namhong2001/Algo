#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist(vector<int> &arr) {
	int ret = 0;
	for (int i=0; i<arr.size()-1; ++i) {
		ret += abs(arr[i] - arr[i+1]);
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int ans = -1;
	do {
		ans = max(ans, dist(arr));
	} while (next_permutation(arr.begin(), arr.end()));
	cout << ans << endl;
	return 0;
} 

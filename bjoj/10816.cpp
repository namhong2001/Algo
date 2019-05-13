#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i=0; i<n; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int m;
	cin >> m;
	while (m--) {
		int v;
		cin >> v;
		auto lower = lower_bound(nums.begin(), nums.end(), v);
		auto upper = upper_bound(nums.begin(), nums.end(), v);
		cout << distance(lower, upper) << ' ';
	}
	return 0;
}

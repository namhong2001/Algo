#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> nums(N);
	for (int i=0; i<N; ++i) {
		cin >> nums[i];
	}
	auto can_divide = [&](int limit) {
		int cnt = 0;
		int sum = 0;
		for (int a : nums) {
			if (a > limit) return false;
			if (sum + a > limit) {
				sum = 0;
				cnt++;
			}
			sum+=a;
		}
		cnt++;
		return cnt <= M;
	};
	int l = 0, r = 30000;
	while (l < r) {
		int mid = (l+r)/2;
		if (can_divide(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << endl;

	int cnt = 0;
	int sum = 0;
	int remain = M;
	for (int i=0; i<N; ++i) {
		if (sum + nums[i] > l) {
			cout << cnt << ' '; 
			sum = 0;
			cnt = 0;
			remain--; 
		} 
		sum+=nums[i];
		cnt++;
		if (N - i == remain) {
			cout << cnt << ' ';
			sum = 0;
			cnt = 0;
			remain--; 
		}
	}
	if (cnt > 0) cout << cnt << ' ';
	return 0;
} 

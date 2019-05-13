#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, h;
	cin >> n >> h;
	vector<int> up;
	vector<int> down;
	for (int i=0; i<n; ++i) {
		int a;
		cin >> a;
		if (i%2) up.push_back(a);
		else down.push_back(a);
	}
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());
	
	int min_obstacle = 987654321;
	int interval_cnt = 0;	
	for (int i=1; i<=h; ++i) {
		int cnt = 0;
		auto lower = lower_bound(up.begin(), up.end(), i);
		cnt += distance(lower, up.end());
		auto upper = upper_bound(down.begin(), down.end(), h-i);
		cnt += distance(upper, down.end());
		if (cnt == min_obstacle) {
			interval_cnt++;
		} else if (cnt < min_obstacle) {
			interval_cnt = 1;
			min_obstacle = cnt;
		}
	}
	cout << min_obstacle << ' ' << interval_cnt << endl;
	return 0;
} 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_cnt(int dist, vector<int> &home) {
	int cnt = 1;
	int cur = 0;
	for (int i=1; i<home.size(); ++i) {
		if(home[i]-home[cur] >= dist) {
			cur = i;
			cnt++;
		}
	}
	return cnt;
}



int main() {
	int n, c;
	cin >> n >> c;
	vector<int> home(n);
	for (int i=0; i<n; ++i) {
		cin >> home[i];
	}
	sort(home.begin(), home.end());
	int l = 1, r = 1e9;
	while (l+1 < r) {
		int mid = (l+r)/2;
		if (get_cnt(mid, home) >= c) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << endl;
	return 0;
}		

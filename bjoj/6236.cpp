#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> money;

int draw_cnt(int k) {
	int cnt = 0;
	int remain = 0;
	for (int m : money) {
		if (remain < m) {
			remain = k;
			cnt++;
		}
		remain -= m;
	}
	return cnt;
}

	

int main() {
	int n, m;
	cin >> n >> m;
	money.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> money[i];
	}
	int l = *max_element(money.begin(), money.end());
	int r = 1e9+1;
	while (l < r) {
		int mid = (l+r)/2;
		if (draw_cnt(mid) > m) {
			l = mid+1;
		} else {
			r = mid;
		}
	}
	cout << l << endl;
	return 0;
} 

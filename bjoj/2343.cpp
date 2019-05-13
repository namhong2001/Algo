#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lessons;

int get_cnt(int limit) { 
	int cur = 0;
	int ret = 0;
	for (int lesson : lessons) {
		if (lesson > limit) return 1e9;
		if (cur + lesson > limit) {
			ret++;
			cur = lesson;
		} else {
			cur += lesson;
		}
	}
	if (cur > 0) ret++;
	return ret;
}


int main() {
	int n, m;
	cin >> n >> m;
	lessons.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> lessons[i];
	}
	int l = 0, r = 1e9+1;
	while (l < r) {
		int mid = (l+r)/2;
		if (get_cnt(mid) > m) {
			l = mid+1;
		} else {
			r = mid;
		}
	}
	cout << l;
	return 0;
} 

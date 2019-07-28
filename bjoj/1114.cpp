#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, K, C;
int first_index; 
bool decision(vector<int> &pos, int limit, int start_index, int max_cnt) {
	int left = pos[start_index];
	int cnt = 0; 
	int pre = left;
	for (int i=start_index+1; i<K+2; ++i) {
		int p = pos[i]; 
		if (p-left > limit) { 
			if (left == pos[start_index]) first_index = i-1;
			cnt++;
			left = pre; 
		}
		if (p-left > limit) {
			return false;
		}
		pre = p;
	}
	if (cnt > max_cnt) return false;
	return true;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> L >> K >> C;
	vector<int> pos(K+2);
	pos[0] = 0;
	for (int i=1; i<=K; ++i) {
		cin >> pos[i];
	}
	pos[K+1] = L;
	sort(pos.begin(), pos.end());
	int l = 0, r = 1e9; // l = false, r = true
	while (l+1 < r) {
		int mid = (l+r)/2;
		if (decision(pos, mid, 0, C)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	int max_len = r;
	decision(pos, r, 0, C); 
	l = 0, r = first_index;
	while (l+1 < r) {
		int mid = (l+r)/2;
		if (decision(pos, max_len, mid, C-1)) {
			r = mid;
		} else {
			l = mid;
		}
	} 
	int left_most = pos[r];
	cout << max_len << ' ' << left_most << endl; 
	return 0;
} 

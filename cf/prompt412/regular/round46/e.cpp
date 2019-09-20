#include <iostream>
#include <vector>

using namespace std;

struct segment {
	int s, e;
};

int N;
vector<int> arr;

bool can_change(int a, int b) {
	if (a < 0 || a >= N || b < 0 || b >= N) return false;
	return arr[a] + 1 < arr[b];
}

int main() { 
	cin >> N;
	if (N == 1 || N == 2) {
		cout << N << endl;
		return 0;
	} 
	arr.resize(N);
	for (int i=0; i<N; ++i) cin >> arr[i];
	vector<segment> seg;
	int s = 0, e = 0;
	int ans = 0;
	for (int i=1; i<N; ++i) {
		if (arr[i-1] < arr[i]) e = i;
		else { 
			seg.push_back({s, e});
			int len = e-s+1;
			if (len < N) len++; 
			ans = max(ans, len);
			s = i;
			e = i;
		}
	}
	seg.push_back({s, e}); 
	/*
	for (auto s : seg) {
		cerr << s.s << ' ' << s.e << endl;
	}
	*/
	int len = e-s+1;
	if (len < N) len++; 
	ans = max(ans, len);

	segment pre = seg[0];
	for (int i=1; i<(int)seg.size(); ++i) {
		segment cur = seg[i];
		int pre_len = pre.e-pre.s+1;
		int cur_len = cur.e-cur.s+1;
		if (pre.e + 1 == cur.s && pre_len > 1 && cur_len > 1) { 
			if (arr[pre.e-1]+1 < arr[cur.s] || arr[pre.e] < arr[cur.s+1]-1) { 
				ans = max(ans, pre_len + cur_len);
			}
		} else if (pre.e + 2 == cur.s) {
			if (can_change(pre.e, cur.s)) {
				ans = max(ans, pre_len + cur_len + 1);
			}
		}
		pre = cur;
	}
	cout << ans;
	return 0;
}

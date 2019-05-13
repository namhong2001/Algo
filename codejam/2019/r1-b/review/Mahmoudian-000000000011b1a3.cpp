// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 2e5 + 6, mod = (int) 0;
int seg[N << 2], ch[N << 2];
void update(int i, int j, int x, int v = 1, int b = 0, int e = N) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v] += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	seg[v] = max(seg[l], seg[r]) + ch[v];
}
int a[N];
vector<int> all[N];
int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		memset(seg, 0, sizeof seg);
		memset(ch, 0, sizeof ch);
		cout << "Case #" << tt << ": ";
		for (int j = 0; j < N; ++j) all[j].clear();
		int n, s;
		cin >> n >> s;
		int res = 0;
		for (int j = 0; j < n; ++j) cin >> a[j], --a[j], all[a[j]].push_back(j);
		for (int j = 0; j < n; ++j) {
			int cur = a[j];
			update(0, j + 1, 1);
			int pos = lower_bound(ALL(all[cur]), j) - all[cur].begin();
			if (pos >= s) {
				int xl = all[cur][pos - s];
				update(0, xl + 1, -1);
				int bef = (pos - s == 0 ? -1 : all[cur][pos - s - 1]);
				update(bef + 1, xl + 1, -s);
			}
			res = max(res, seg[1]);
		}
		cout << res << '\n';
	}
}


















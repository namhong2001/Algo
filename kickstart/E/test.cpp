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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int o[N], e[N], c[N], sc[N], se[N];
int cmp(int x, int y) {
	return c[x] * e[y] > c[y] * e[x];
}
int32_t main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		cout << "Case #" << tt << ": ";
		int q, n;
		cin >> q >> n;
		int sume = 0, sumc = 0;
		for (int j = 0; j < n; ++j) {
			cin >> c[j] >> e[j];
			sume += e[j];
			sumc += c[j];
			o[j] = j;
		}
		sort(o, o + n, cmp);
		for (int i = 0; i < n; ++i) {
			int j = o[i];
			sc[i + 1] = sc[i] + c[j];
			se[i + 1] = se[i] + e[j];
		}
		while (q--) {
			int a, b;
			cin >> a >> b;
			cout << '\n';
			if (a > sumc || b > sume) {
				cout << 'N';
				continue;
			}
			int pos = upper_bound(sc, sc + n, a) - sc - 1;
			int cur_e = sume - se[pos];
			a -= sc[pos];
			int j = o[pos];
			if (cur_e * c[j] - a * e[j] >= b * c[j]) {
				cout << 'Y';	
			} else {
				cout << 'N';
			}
		}
		cout << '\n';
	}
} 

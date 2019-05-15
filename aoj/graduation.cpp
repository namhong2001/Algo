#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef unsigned int ui;

const int INF = 987654321;

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, k, m, l;
        cin >> n >> k >> m >> l;
        vector<ui> pre(n, 0);
        for (int i=0; i<n; ++i) {
            int r;
            cin >> r;
            ui p = 0;
            for (int j=0; j<r; ++j) {
				ui a;
				cin >> a;
				p |= 1<<a;
			}
			pre[i] = p;
		}
		vector<ui> d(1<<n, INF);
		d[0] = 0;
		for (int i=0; i<m; ++i) {
			int c;
			cin >> c;
			ui open = 0;
			for (int j=0; j<c; ++j) {
				int a;
				cin >> a;
				open |= 1<<a; 
			}
			vector<ui> nd = d;
			for (ui t=open; t; t = t-1 & open) {
				if (__builtin_popcount(t) <= l) { 	
					bool has_pre = false;
					for (int k=0; k<n; ++k) {
						if ((t & 1<<k) && (pre[k] & t)) has_pre = true;
					}
					if (has_pre) continue;

					for (int j=0; j < 1<<n; ++j) {
						if (j & t) continue;
						if (d[j] == INF) continue;
						bool isok = true;
						for (int k=0; k<n; ++k) {
							if ((t & 1<<k) && (pre[k] & j) != pre[k]) isok = false;
						}
						if (!isok) continue;
						nd[j|t] = min(nd[j|t], d[j]+1);
					}
				}
			}
			d = nd;
		}
		ui ans = INF;
		for (ui i=0; i<1<<n; ++i) {
			if (__builtin_popcount(i) >= k) {
				ans = min(ans, d[i]); 
			}
		}
		if (ans == INF) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
} 

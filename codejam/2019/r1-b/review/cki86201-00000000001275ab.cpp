#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N, K;
int A[100010], B[100010], C[100010], D[100010];
int pp[100010], lv[100010]; int Find(int x) { return pp[x] == x ? x : pp[x] = Find(pp[x]); }
int chk[100010];

ll Do() {
	for(int i=1;i<=N;i++) pp[i] = lv[i] = i;
	auto merge = [&](int x, int y) {
		x = Find(x), y = Find(y);
		if(x > y) swap(x, y);
		pp[x] = y;
		lv[y] = lv[x];
	};
	vector <pii> v;
	for(int i=1;i<=N;i++) v.pb(pii(A[i], i));
	for(int i=1;i<=N;i++) v.pb(pii(B[i], -i));
	sort(all(v));
	set <int> Sx;
	for(int i=0;i<=N+1;i++) Sx.insert(i);
	for(int i=1;i<=N;i++) chk[i] = 0;
	ll res = 0;
	for(pii e : v) {
		if(e.Se < 0) {
			Sx.erase(-e.Se);
		}
		else {
			int a = e.Se;
			
			if(chk[a-1]) merge(a, a-1);
			if(chk[a+1]) merge(a, a+1);
			chk[a] = 1;
			
			if(Sx.find(a) != Sx.end()) continue;
			int l = lv[Find(a)], r = Find(a);
			auto it = Sx.upper_bound(a);
			r = min(r, *it - 1);
			--it;
			l = max(l, *it + 1);
			res += (ll) (r - a + 1) * (a - l + 1);
		}
	}
	return res;
}

void solve() {
	scanf("%d%d", &N, &K);
	for(int i=1;i<=N;i++) scanf("%d", C + i);
	for(int i=1;i<=N;i++) scanf("%d", D + i);
	ll ans = (ll)N * (N + 1) / 2;
	for(int i=1;i<=N;i++) A[i] = C[i], B[i] = D[i] + K + 1;
	ans -= Do();
	for(int i=1;i<=N;i++) A[i] = D[i], B[i] = C[i] + K + 1;
	ans -= Do();
	printf("%lld\n", ans);
	
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}

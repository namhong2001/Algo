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

int xx[100010], yy[100010];

void solve() {
	int p, q; scanf("%d%d", &p, &q);
	rep(i, q + 5) xx[i] = yy[i] = 0;
	for(int i=1;i<=p;i++) {
		int x, y; char ch;
		scanf("%d%d %c", &x, &y, &ch);
		if(ch == 'N') yy[y+1]++;
		else if(ch == 'S') yy[0]++, yy[y]--;
		else if(ch == 'E') xx[x+1]++;
		else xx[0]++, xx[x]--;
	}
	for(int i=1;i<=q;i++) xx[i] += xx[i-1], yy[i] += yy[i-1];
	int x = 0, y = 0;
	for(int i=1;i<=q;i++) {
		if(xx[i] > xx[x]) x = i;
		if(yy[i] > yy[y]) y = i;
	}
	printf("%d %d\n", x, y);
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}

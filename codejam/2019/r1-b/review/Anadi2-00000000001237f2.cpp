#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;

int n, q;
int pref[2][N];

void solve(){
	scanf("%d %d", &n, &q);
	for(int i = 0; i <= q; ++i)
		pref[0][i] = pref[1][i] = 0;

	for(int i = 1; i <= n; ++i){
		int x, y; char d;
		scanf("%d %d %c", &x, &y, &d);
		
		if(d == 'N')
			pref[1][y + 1]++;
		if(d == 'S')
			pref[1][0]++, pref[1][y]--;

		if(d == 'W')
			pref[0][0]++, pref[0][x]--;
		if(d == 'E')
			pref[0][x + 1]++;
	}
	
	for(int i = 1; i <= q; ++i){
		pref[0][i] += pref[0][i - 1];
		pref[1][i] += pref[1][i - 1];
	}

	int besty = 0, bestx = 0;
	for(int i = 1; i <= q; ++i){
		if(pref[0][i] > pref[0][bestx])
			bestx = i;
		if(pref[1][i] > pref[1][besty])
			besty = i;
	}
	
	printf("%d %d\n", bestx, besty);
}

int main(){
	int cases;
	scanf("%d", &cases);

	for(int i = 1; i <= cases; ++i){
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}
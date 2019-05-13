#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;

LL ask(int v){
	printf("%d\n", v);
	fflush(stdout);
	
	LL ret;
	scanf("%lld", &ret);
	return ret;
}

LL res[10];

void solve(){
	LL ans1 = ask(50);
	LL ans2 = ask(200);
	
	res[1] = ans1 - (ans1%(1LL << 50));
	res[2] = ans1 - res[1] - (ans1%(1LL << 25));

	res[4] = ans2 - (ans2%(1LL << 50));
	res[5] = ans2 - res[4] - (ans2%(1LL << 40));
	res[6] = ans2 - res[4] - res[5] - (ans2%(1LL << 33));
	
	res[1] /= 1LL << 50;
	res[2] /= 1LL << 25;
	res[4] /= 1LL << 50;
	res[5] /= 1LL << 40;
	res[6] /= 1LL << 33;
	
	res[3] = ans1 - res[1] * (1LL << 50) - res[2] * (1LL << 25) - res[4] * (1LL << 12) - res[5] * (1LL << 10) - res[6] * (1LL << 8);
	res[3] /= 1LL << 16;

	printf("%lld %lld %lld %lld %lld %lld\n", res[1], res[2], res[3], res[4], res[5], res[6]);
	fflush(stdout);
	
	int cor;
	scanf("%d", &cor);
	assert(cor == 1);
}

int main(){
	int cases, rq;
	scanf("%d %d", &cases, &rq);
	
	while(cases--)
		solve();
	return 0;
}
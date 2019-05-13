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

LL ans;
int n, k;
set <int> A, B, C;
priority_queue <PII> Q1, Q2, Q3;

void solve(){
	ans = 0;
	A.clear(), B.clear(), C.clear();

	while(!Q1.empty())	Q1.pop();
	while(!Q2.empty())	Q2.pop();
	while(!Q3.empty())	Q3.pop();

	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);		
		Q1.push({-a, i});
	}
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		Q2.push({-a, i});
		Q3.push({-a, i});
	}
	
	for(int i = 0; i <= n + 1; ++i)
		A.insert(i), B.insert(i), C.insert(i);
	
	while(!Q1.empty()){
		int v = -Q1.top().st;
		int id = Q1.top().nd;
		Q1.pop();//printf("%d -> %lld\n", id, ans);
		
		A.erase(id);
		while(!Q2.empty() && -Q2.top().st <= v + k){
			B.erase(Q2.top().nd);
			Q2.pop();
		}
		
		while(!Q3.empty() && -Q3.top().st < v - k){
			C.erase(Q3.top().nd);
			Q3.pop();
		}
		
		auto it = A.lower_bound(id);
		int R = *it - 1;
		int L = *(--it) + 1;
		
		if(B.find(id) != B.end())
			continue;
		
		it = B.lower_bound(id);
		R = min(R, *it - 1);
		L = max(L, *(--it) + 1);
		
		if(R < L)
			continue;
		//printf("%d %d\n", L, R);
		if(C.find(id) != C.end()){
			ans += 1LL * (R - id + 1) * (id - L + 1);
			continue;
		}

		it = C.lower_bound(id);
		int cR = *it;
		int cL = *(--it);
		
		if(cL < L && R < cR)
			continue;
//		printf("%d %d\n", cL, cR);
		if(L <= cL && cR <= R){
			ans += 1LL * (id - L + 1) * (R - id + 1);
			ans -= (id - cL) * (cR - id);
			continue;
		}
		
		if(L <= cL)
			ans += 1LL * (R - id + 1) * (cL - L + 1);
		else
			ans += 1LL * (id - L + 1) * (R - cR + 1);
	}

	printf("%lld\n", ans);fflush(stdout);
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
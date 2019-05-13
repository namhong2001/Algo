#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int num_tests, limit;
int ans[7], Q;
long long ret;

void interact(){
	
	// first query
	Q = 224;
	printf("%d\n", Q);
	fflush(stdout);
	scanf("%lld", &ret);
	ans[4] = ret >> 56;
	ans[5] = (ret % (1LL << 56)) >> 44;
	ans[6] = (ret % (1LL << 44)) >> 37;
	
	// second query
	Q = 56;
	printf("%d\n", Q);
	fflush(stdout);
	scanf("%lld", &ret);
	ret -= ans[4] * (1 << 14);
	ret -= ans[5] * (1 << 11);
	ret -= ans[6] * (1 << 9);
	
	ans[1] = ret >> 56;
	ans[2] = (ret % (1LL << 56)) >> 28;
	ans[3] = (ret % (1LL << 28)) >> 18;
	
	
	// answer
	for(int i = 1; i <= 6; i++)
		printf("%d%c", ans[i], i == 6 ? '\n':' ');
	fflush(stdout);
	
	int verdict;
	scanf("%d", &verdict);
	
	return;
}

int main(){
	scanf("%d %d", &num_tests, &limit);
	for(int t = 1; t <= num_tests; t++){
		interact();
	}
	return 0;
}

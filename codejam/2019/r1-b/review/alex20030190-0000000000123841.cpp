#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int num_tests;
int n, b;
int hori_count[100005];
int vert_count[100005];

void solve(){
	scanf("%d %d", &n, &b);
	memset(hori_count, 0, sizeof(hori_count));
	memset(vert_count, 0, sizeof(vert_count));
	for(int i = 1; i <= n; i++){
		int x, y;
		char dir;
		scanf("%d %d %c", &x, &y, &dir);
		
		if(dir == 'E'){
			hori_count[x + 1]++;
		}
		else if(dir == 'W'){
			hori_count[0]++;
			hori_count[x]--;
		}
		else if(dir == 'N'){
			vert_count[y + 1]++;
		}
		else if(dir == 'S'){
			vert_count[0]++;
			vert_count[y]--;
		}
	}
	int optx = 0, opty = 0;
	for(int i = 1; i <= b; i++){
		hori_count[i] += hori_count[i - 1];
		if(hori_count[i] > hori_count[optx]){
			optx = i;
		}
		vert_count[i] += vert_count[i - 1];
		if(vert_count[i] > vert_count[opty]){
			opty = i;
		}
	}
	printf("%d %d\n", optx, opty);
}

int main(){
	scanf("%d", &num_tests);
	for(int t = 1; t <= num_tests; t++){
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
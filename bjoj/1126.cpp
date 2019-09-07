#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int blocks[52]; 
int d[51][500001]; // d[nth][height_diff] = longest_height
int solve(int n, int diff) {
	if (n == 0) {
		if (diff == 0) return 0;
		else return -INF;
	}
	int &ret = d[n][diff];
	if (ret != -1) return ret;
	ret = -INF;
	ret = max(ret, solve(n-1, diff));
	ret = max(ret, solve(n-1, diff+blocks[n]));
	if (diff >= blocks[n]) {
		ret = max(ret, solve(n-1, diff-blocks[n]) + blocks[n]);
	} else {
		ret = max(ret, solve(n-1, blocks[n]-diff) + diff);
	}
	return ret;
} 

int main() {
	memset(d, -1, sizeof(d));
	int N;
	cin >> N;
	for (int i=1; i<=N; ++i) cin >> blocks[i];
	cout << (solve(N, 0) > 0 ? solve(N, 0) : -1); 
	return 0;
}


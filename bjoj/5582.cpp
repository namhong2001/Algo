#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int d[4001][4001];
string A, B;
int N, M;
int solve(int a, int b) {
	if (a<0 || b<0) return 0;
	if (A[a] != B[b]) return 0;
	int &ret = d[a][b];
	if (ret != -1) return ret;
	return ret = solve(a-1, b-1)+1;
}


int main() {
	cin >> A >> B;
	N = A.size();
	M = B.size();
	memset(d, -1, sizeof(d));
	int ans = 0;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			ans = max(ans, solve(i, j));
		}
	} 
	cout << ans; 
	return 0;
}


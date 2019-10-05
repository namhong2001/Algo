#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int d[1001][1001];
string A, B;

void trackback(int n, int m, int len) {
	if (len == 0) return;
	for (int j=m; j>=0; --j) { 
		if (d[n][j] == len) {
			while (d[n][j] == len) n--;
			trackback(n, j-1, len-1);
			cout << B[j];
			break;
		}
	}
} 

int main() {
	cin >> A >> B;
	N = A.size();
	M = B.size();
	A.insert(A.begin(), '0');
	B.insert(B.begin(), '0');
	for (int i=1; i<=N; ++i) {
		int max_prefix = 0;
		for (int j=1; j<=M; ++j) { 
			d[i][j] = d[i-1][j];
			if (A[i] == B[j]) d[i][j] = max_prefix+1;
			max_prefix = max(max_prefix, d[i-1][j]);
		}
	}
	int len = *max_element(d[N]+1, d[N]+M+1); 
	cout << len << '\n';
	trackback(N, M, len); 
	return 0;
}


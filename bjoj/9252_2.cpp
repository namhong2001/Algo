#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string A, B;
int N, M;
int d[1001][1001];

void trackback(int n, int m) { 
	if (d[n][m] == 0) return;
	if (n > 0 && d[n-1][m] == d[n][m]) trackback(n-1, m);
	else if (m > 0 && d[n][m-1] == d[n][m]) trackback(n, m-1);
	else {
		trackback(n-1, m-1);
		cout << A[n];
	}
} 

int main() {
	cin >> A >> B;
	N = A.size();
	M = B.size();
	A.insert(A.begin(), '0');
	B.insert(B.begin(), '0'); // padding 
	for (int i=1; i<=N; ++i) {
		for (int j=1; j<=M; ++j) {
			if (A[i] == B[j]) d[i][j] = d[i-1][j-1] + 1;
			else d[i][j] = max(d[i-1][j], d[i][j-1]);
		}
	}
	cout << d[N][M] << endl;
	trackback(N, M);
	return 0;
}


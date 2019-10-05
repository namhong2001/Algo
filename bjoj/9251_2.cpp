#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	int N = A.size();
	int M = B.size();
	A.insert(A.begin(), '0');
	B.insert(B.begin(), '0'); // padding 
	int d[2][M+1];
	memset(d, 0, sizeof(d)); 
	int *prev = d[0];
	int *cur = d[1];
	for (int i=1; i<=N; ++i) {
		for (int j=1; j<=M; ++j) {
			if (A[i] == B[j]) cur[j] = prev[j-1] + 1;
			else cur[j] = max(prev[j], cur[j-1]);
		}
		swap(prev, cur);
	}
	cout << prev[M];
	return 0;
}


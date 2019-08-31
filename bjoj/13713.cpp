#include <iostream>
#include <algorithm>

using namespace std;

int Z[1000000];

void zfunc(string &S) {
	int N = S.size();
	int L = 0, R = 0;
	for (int i=1; i<N; ++i) {
		if (i>R) {
			L = R = i;
			while (R<N && S[R-L] == S[R]) R++;
			Z[i] = R-L;
			R--;
		} else {
			if (Z[i-L] < R-i+1) Z[i] = Z[i-L];
			else {
				L = i;
				while (R<N && S[R-L] == S[R]) R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
	Z[0] = N;
}

int query(int pos) { 
	return Z[pos];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string S;
	cin >> S;
	reverse(S.begin(), S.end());
	zfunc(S);
	int M; 
	cin >> M;
	int N = S.size();
	for (int i=0; i<M; ++i) {
		int q;
		cin >> q;
		cout << query(N-q) << '\n';
	} 
	return 0;
}


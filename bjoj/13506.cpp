#include <iostream>
#include <map>

using namespace std;

string solve(string &S) {
	int N = S.size();
	int L = 0, R = 0;
	int Z[N] = {};
	for (int i=1; i<N; ++i) {
		if (i>R) {
			L = R = i;
			while (R < N && S[R-L] == S[R]) R++;
			Z[i] = R-L;
			R--;
		} else {
			if (Z[i-L] < R-i+1) Z[i] = Z[i-L]; 
			else {
				L = i;
				while (R < N && S[R-L] == S[R]) R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
	map<int, int> cnt;
	for (int i=1; i<N; ++i) {
		if (Z[i] > 0) {
			cnt[Z[i]]++;
		}
	}
	int ret = -1;
	for (int i=1; i<N; ++i) {
		if (Z[i] == N-i && (cnt.upper_bound(N-i) != cnt.end() || cnt[N-i] > 1) && N-i > ret) ret = N-i;
	}
	if (ret == -1) return "-1"; 
	return S.substr(0, ret);
} 

int main() {
	string S;
	cin >> S;
	cout << solve(S) << '\n'; 
	return 0;
}


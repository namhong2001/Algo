#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9+7;


int N;
int d[100002];
int S[100002];

int solve(int pos) {
	if (pos == N) return 1;
	if (pos > N) return 0;
	int &ret = d[pos];
	if (ret != -1) return ret;
	ret = 0;
	ret += solve(pos+1) + solve(pos+S[pos]);
	ret %= MOD;
	return ret;
}

int main() {
	cin >> N;
	memset(d, -1, sizeof(d));
	for (int i=1; i<=N; ++i) {
		cin >> S[i];
	}
	cout << solve(1); 
    return 0;
}


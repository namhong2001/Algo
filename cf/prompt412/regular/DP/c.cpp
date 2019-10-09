#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N;
int d[100002];
int S[100002];

int solve(int pos) {
	if (pos == N) return 0;
	if (pos > N) return INF;
	int &ret = d[pos];
	if (ret != -1) return ret;
	return ret = min(solve(pos+1),  solve(pos+S[pos])) + 1;
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


#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321; 

int cal[5001];
int price[5001]; 
int N, M;
int d[10001];
int solve(int M) {
	if (M < 0) return -INF;
	if (M == 0) return 0;
	int &ret = d[M];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=1; i<=N; ++i) {
		ret = max(ret, solve(M - price[i]) + cal[i]);
	}
	return ret;
}

int main() {
	while (true) {
		memset(d, -1, sizeof(d));
		double m;
		cin >> N >> m;
		M = m*100;
		if (N == 0 && M == 0) break;
		for (int i=1; i<=N; ++i) { 
			int C;
			double p;
			cin >> C >> p; 
			int P = p*100;
			cal[i] = C;
			price[i] = P;
		}
		cout << solve(M) << '\n';
	} 
	return 0;
}


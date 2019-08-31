#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int INF = 987654321;

vector<int> coins; 
vector<int> d(10001, -1);

int solve(int K) { 
	if (K < 0) return INF;
	if (K == 0) return 0;
	int &ret = d[K];
	if (ret != -1) return ret;
	int N = coins.size(); 
	ret = INF;
	for (int i=0; i<N; ++i) {
		ret = min(ret, solve(K-coins[i]));
	}
	if (ret < INF) ret++;
	return ret; 
}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i=0; i<N; ++i) {
		int c;
		cin >> c;
		coins.push_back(c);
	}
	sort(coins.begin(), coins.end());
	coins.erase(unique(coins.begin(), coins.end()), coins.end());
	cout << (solve(K) == INF ? -1 : solve(K));
	return 0;
}


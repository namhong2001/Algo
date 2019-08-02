#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> P(M);
	for (int i=0; i<M; ++i) {
		cin >> P[i];
	}
	int price = INF;
	int profit = 0;
	sort(P.begin(), P.end());
	for (int i=0; i<M; ++i) {
		int cur_price = P[i];
		int cur_profit = min(N, M-i)*cur_price;
		if (cur_profit > profit) {
			profit = cur_profit;
			price = cur_price;
		}
	}
	cout << price << ' ' << profit << endl;
	return 0;
} 

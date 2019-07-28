#include <iostream>
#include <vector>

using namespace std;

vector<int> P;
int N, M;
int profit(int price) {
	int cnt = 0;
	for (auto p : P) {
		if (p >= price) {
			cnt++;
		}
	}
	return price * min(cnt, N);
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	P.resize(M);
	for (int i=0; i<M; ++i) {
		cin >> P[i];
	}
	int l = 0, r = 1e6+1;
	while (l+2<r) {
		int a = (2*l+r)/3;
		int b = (l+2*r)/3;
		if (profit(a) < profit(b)) {
			l = a;
		} else {
			r = b;
		}
	}
	int ans = (l+r)/2;
	int max_profit = profit(ans);
	l = 0, r = ans; // false, true
	while (l+1<r) {
		int mid = (l+r)/2;
		if (profit(mid) == max_profit) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << ' ' << max_profit << endl;
	return 0;
} 

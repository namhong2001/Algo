#include <iostream>
#include <deque>

using namespace std;

typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	int d[M+1] = {};
	for (int i=1; i<=N; ++i) {
		int v, c, k;
		cin >> v >> c >> k;
		for (int r=0; r<v; ++r) {
			deque<pii> dq;
			for (int j=0; v*j+r<=M; ++j) {
				int val = d[v*j+r] - c*j;
				while (!dq.empty() && dq.back().first <= val) dq.pop_back();
				dq.emplace_back(val, j);
				if (j - dq.front().second > k) dq.pop_front();
				d[v*j+r] = dq.front().first + c*j;
			}
		}
	}
	cout << d[M]; 
	return 0;
}


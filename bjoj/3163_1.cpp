#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N, L, K; 
		cin >> N >> L >> K;
		vector<pii> order;
		vector<int> ids(N);
		for (int i=0; i<N; ++i) { 
			int p, id;
			cin >> p >> id;
			ids[i] = id;
			if (id < 0) { 
				order.emplace_back(p, id);
			} else {
				order.emplace_back(L-p, id);
			}
		}
		sort(order.begin(), order.end());
		int left = 0;
		int right = N-1;
		vector<pii> fall;
		for (int i=0; i<min(K+1, N); ++i) {
			order[i].second < 0 ?  fall.emplace_back(order[i].first, ids[left++])
				: fall.emplace_back(order[i].first, ids[right--]);
		}
		sort(fall.begin(), fall.end());
		cout << fall[K-1].second << '\n';
	} 
	return 0;
} 

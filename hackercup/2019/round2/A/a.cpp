#include <iostream>
#include <cmath>

using namespace std; 

typedef pair<int,int> pii;

int dist(int a, int b, int x, int y) {
	return abs(x-a) + abs(y-b);
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		int N, M, K;
		cin >> N >> M >> K;
		pii mrx;
		pii agents[K];
		cin >> mrx.first >> mrx.second;
		for (int i=0; i<K; ++i) { 
			cin >> agents[i].first >> agents[i].second;
		} 
		char ans;
		if (K == 1) {
			ans = 'N'; 
		} else {
			bool surren = true;
			for (int i=0; i<K; ++i) { 
				if (dist(mrx.first, mrx.second, agents[i].first, agents[i].second) % 2) surren = false;
			}
			if (surren) ans = 'Y';
			else ans = 'N';
		}
		cout << "Case #" << t << ": " << ans << '\n';
	} 
	return 0;
}

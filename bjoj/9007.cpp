#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int K, N;
		cin >> K >> N;
		vector<int> A, B; 
		A.reserve(N*N);
		B.reserve(N*N);
		int in[4][N];
		for (int k=0; k<4; ++k) {
			for (int i=0; i<N; ++i) {
				cin >> in[k][i];
			} 
		}
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				A.push_back(in[0][i] + in[1][j]);
			}
		}
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				B.push_back(in[2][i] + in[3][j]);
			}
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		B.erase(unique(B.begin(), B.end()), B.end()); 

		int ans = INF;
		int diff = INF;
		for (auto a : A) { 
			auto lower = lower_bound(B.begin(), B.end(), K-a);
			if (lower != B.end() && *lower+a-K < diff) {
				ans = *lower+a;
				diff = *lower+a-K;
			}
			if (lower != B.begin()) {
				auto pre = prev(lower);
				if (K-(*pre+a) <= diff) {
					ans = *pre + a;
					diff = K-(*pre+a);
				}
			}
		} 
		cout << ans << '\n';
	}
	return 0;
} 

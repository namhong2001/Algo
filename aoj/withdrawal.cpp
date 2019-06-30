#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> R(N);
		vector<int> C(N); 
		for (int i=0; i<N; ++i) {
			cin >> R[i] >> C[i];
		}
		int rsum = 0;
		int csum = 0; 
		vector<bool> used(N, false);
		auto find_next = [&]() {
			double min_rank = 1.0;
			int ret = -1;
			for (int i=0; i<N; ++i) {
				if (used[i]) continue;
				int trsum = rsum + R[i];
				int tcsum = csum + C[i];
				double trank = 1.0*trsum/tcsum;
				if (trank < min_rank) {
					min_rank = trank;
					ret = i;
				}
			}
			return ret;
		};
		for (int i=0; i<K; ++i) { 
			int next = find_next();
			used[next] = true;
			rsum += R[next];
			csum += C[next];
		}
		cout << fixed << setprecision(10) << 1.0*rsum/csum << '\n';
	}
	return 0;
} 

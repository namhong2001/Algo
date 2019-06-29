#include <iostream>
#include <vector>
#include <algorithm>
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
		auto can_rank = [&](double rank) {
			vector<double> factor(N);
			for (int i=0; i<N; ++i) {
				factor[i] = C[i]*rank - R[i];
			}
			sort(factor.begin(), factor.end(), greater<double>());
			double sum = 0;
			for (int i=0; i<K; ++i) {
				sum += factor[i];
			}
			return sum >= 0.0;
		};
		double l = 0.0, r = 1.0;
		for (int i=0; i<100; ++i) {
			double mid = (l+r)/2.0;
			if (can_rank(mid)) r = mid;
			else l = mid;
		}
		cout << fixed << setprecision(10) << l << '\n';
	}
	return 0;
} 

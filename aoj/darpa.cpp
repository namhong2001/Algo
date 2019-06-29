#include <iostream>
#include <vector>
#include <iomanip>

using namespace std; 

int main() {
	int C;
	cin >> C; 
	while (C--) {
		int N, M;
		cin >> N >> M;
		vector<double> pos(M);
		for (int i=0; i<M; ++i) {
			cin >> pos[i];
		}
		auto can_set = [&](double range) {
			double end = 0;
			int cnt = 0;
			for (double p : pos) {
				if (p >= end) {
					cnt++;
					end = p+range;
				}
			}
			return cnt >= N; 
		};
		double l = 0, r = 240;
		for (int i=0; i<100; ++i) {
			double mid = (l+r)/2;
			if (can_set(mid)) l = mid;
			else r = mid;
		}
		
		cout << fixed << setprecision(2) << l << '\n';
	}
	return 0;
} 

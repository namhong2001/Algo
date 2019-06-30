#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		vector<vector<double>> dist(N, vector<double>(N, 0));
		vector<double> xpos(N);
		vector<double> ypos(N);
		for (int i=0; i<N; ++i) {
			cin >> xpos[i] >> ypos[i];
			for (int j=0; j<i; ++j) {
				dist[i][j] = dist[j][i] = sqrt(
						(xpos[i]-xpos[j])*(xpos[i]-xpos[j]) +
						(ypos[i]-ypos[j])*(ypos[i]-ypos[j]) );
			}
		}
		for (int k=0; k<N; ++k) {
			for (int i=0; i<N; ++i) { 
				for (int j=0; j<N; ++j) {
					dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
				}
			}
		}
		double ans = 0;
		for (int i=0; i<N; ++i) {
			for (int j=0; j<i; ++j) {
				ans = max(ans, dist[i][j]);
			}
		}
		cout << fixed << setprecision(2) << ans << '\n';
	}
	return 0;
} 

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<vector<double>> dist;
vector<double> xpos;
vector<double> ypos;
int N;

double get_dist(int a, int b) {
	return sqrt(
			(xpos[a]-xpos[b])*(xpos[a]-xpos[b]) + 
			(ypos[a]-ypos[b])*(ypos[a]-ypos[b]) );
}

vector<bool> visited;
int cnt=0;
void dfs(int here, double range) { 
	visited[here] = true;
	cnt++;
	for (int there=0; there<N; ++there) {
		if (visited[there] || dist[here][there] > range) continue;
		dfs(there, range);
	}
} 

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N;
		xpos.resize(N);
		ypos.resize(N);
		dist.assign(N, vector<double>(N));
		for(int i=0; i<N; ++i) {
			cin >> xpos[i] >> ypos[i];
			for (int j=0; j<i; ++j) {
				dist[i][j] = dist[j][i] = get_dist(i, j);
			}
		}
		double l = 0, r = 1500;
		for (int i=0; i<100; ++i) {
			double mid = (l+r)/2;
			visited.assign(N, false);
			cnt = 0;
			dfs(0, mid);
			if (cnt == N) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout << fixed << setprecision(2) << l << '\n';
	}
	return 0;
} 

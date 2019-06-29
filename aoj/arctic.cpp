#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <iomanip>

using namespace std; 

typedef tuple<double,int,int> tdii;

vector<int> r;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]);
}

void u(int a, int b) {
	a = f(a), b = f(b);
	r[a] = b;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;

		r.resize(N);
		for (int i=0; i<N; ++i) r[i] = i;

		vector<double> xpos(N);
		vector<double> ypos(N);
		vector<tdii> edges; 
		auto get_dist = [&](int a, int b) {
			return sqrt(
					(xpos[a]-xpos[b])*(xpos[a]-xpos[b]) +
					(ypos[a]-ypos[b])*(ypos[a]-ypos[b]) );
		};
		for (int i=0; i<N; ++i) {
			cin >> xpos[i] >> ypos[i];
			for (int j=0; j<i; ++j) {
				edges.emplace_back(get_dist(i, j), i, j);
			}
		}
		sort(edges.begin(), edges.end());
		int cnt = 0;
		double ans = 0;
		for (tdii &edge : edges) {
			double dist;
			int a, b;
			tie(dist, a, b) = edge;
			if (f(a) == f(b)) continue;
			cnt++;
			ans = dist;
			u(a, b);
			if (cnt == N-1) break;
		}
		cout << fixed << setprecision(2) << ans << '\n';
	}
	return 0;
} 

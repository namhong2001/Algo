#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct Edge {
	int a, b, w;
	bool operator < (const Edge &E) {
		return w < E.w;
	}
};

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		int N, M;
		cin >> N >> M;
		vector<Edge> req;
		for (int i=0; i<M; ++i) {
			int a, b, z;
			cin >> a >> b >> z;
			a--, b--;
			req.push_back({a, b, z});
		}
		sort(req.begin(), req.end()); 
		vector<vector<int>> dist(N, vector<int>(N, INF)); 
		for (int i=0; i<N; ++i) {
			dist[i][i] = 0;
		} 
		bool isOk = true;
		vector<Edge> ans;
		for (Edge& e : req) {
			if (dist[e.a][e.b] < e.w) { 
				isOk = false;
				break;
			} else if (dist[e.a][e.b] == e.w) {
			   continue;
			} else {
				dist[e.a][e.b] = dist[e.b][e.a] = e.w;
				ans.push_back(e);
				for (int i=0; i<N; ++i) {
					for (int j=0; j<N; ++j) {
						dist[i][j] = min({
								dist[i][j], 
								dist[i][e.a] + e.w + dist[e.b][j],
								dist[i][e.b] + e.w + dist[e.a][j] 
								});
					}
				}
			}
		}
		if (!isOk) {
			cout << "Case #" << t << ": " << "Impossible" << '\n';
		} else {
			cout << "Case #" << t << ": " << ans.size() << '\n';
			for (Edge &e : ans) {
				cout << e.a+1 << ' ' <<  e.b+1 << ' ' << e.w << '\n';
			}
		}
	}
	return 0;
} 

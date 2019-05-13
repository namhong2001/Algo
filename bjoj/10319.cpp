#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>

using namespace std;

struct Edge {
    int u, v, cap, flow=0;
	int time;
	Edge *op;
	int residue() {
		return this->cap - this.flow;
	}
    bool operator < (const Edge &A) const {
        return this->u < A.u;
    }
};

struct Network_flow {
	vector<Edge> edges;
	Network_flow() {}
	Network_flow(int V) {
		edges.resize(V);	
	}
	
	void add_edge(int u, int v, int cap, int time) {
		Edge e(u, v, cap, 0, time);

		



};

const int INF = 987654321;

map<Edge, int> capacity;
map<Edge, int> flow;



vector<vector<int>> capacity, need_time;
vector<vector<vector<int>>> flow;
vector<vector<int>> adj;
unordered_set<int> hospital;
int N, I, G, S, M, R;


int dfs(int here, int cur_min, int elapsed, vector<bool> &visited) {
//    cout << here << ' ' << cur_min << ' ' << elapsed <<  endl;
    visited[here] = true;
    if (hospital.find(here) != hospital.end()) return cur_min;
    for (int there : adj[here]) {
        if (visited[there]) continue;
        int e = elapsed;
        while (e + need_time[here][there] <= S) {
            int residue = capacity[here][there] - flow[here][there][e];
            if (residue > 0) {
                int f = dfs(there, min(cur_min, residue), e+need_time[here][there], visited);
                if (f > 0) {
                    flow[here][there][e] += f;
                    flow[there][here][e] -= f;
                    cout << here << ' ' << there << ' ' << e << ' ' << f << endl;
                    return f;
                }
            }
            ++e;
        }
    }
    visited[here] = false;
    return 0;
}

int max_flow(int source) {
    int total = 0;
    while (total < G) {
        vector<bool> visited(N, false);
        int f = dfs(source, INF, 0, visited);
        if (f == 0) break;
        total += f;
    }
    return min(total, G);
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> I >> G >> S >> M;
        capacity.assign(N, vector<int>(N, 0));
        flow.assign(N, vector<vector<int>>(N, vector<int>(S, 0)));
        need_time.assign(N, vector<int>(N, 0));
        adj.clear();
        adj.resize(N);
        hospital.clear();
        for (int i=0; i<M; ++i) {
            int a;
            cin >> a;
            a--;
            hospital.insert(a);
        }
        cin >> R;
        for (int i=0; i<R; ++i) {
            int A, B, P, T;
            cin >> A >> B >> P >> T;
            A--, B--;
            adj[A].push_back(B);
            adj[B].push_back(A);
            capacity[A][B] = P;
            need_time[A][B] = T;
        }

        cout << max_flow(I-1) << endl;
        cout << flow[2][0][1] <<  endl;
    }

    return 0;
}

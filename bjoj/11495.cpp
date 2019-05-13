#include <iostream>
#include <vector>


using namespace std;

const int INF = 987654321;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
int V;

vector<vector<int>> adj;
vector<vector<int>> board;
vector<vector<int>> capacity, flow;

int get_id(int i, int j) {
    int order = i*m+j;
    return 2+order;
}

bool in_range(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

bool is_set_a(int i, int j) {
    return (i+j)%2;
}


vector<bool> visited;
int dfs(int here, int sink, int cur_min) {
    visited[here] = true;
    if (here == sink) return cur_min;
    for (int there : adj[here]) {
        if (!visited[there] &&
            capacity[here][there] - flow[here][there] > 0) {
            int f = dfs(there, sink, min(cur_min, capacity[here][there] - flow[here][there]));
            if (f>0) {
                flow[here][there] += f;
                flow[there][here] -= f;
                return f;
            }
        }
    }
    return 0;
}

int network_flow(int src, int sink) {
    int max_flow = 0;
    while (true) {
        visited.assign(V, false);
        int f = dfs(src, sink, INF);
        if (f == 0) break;
        max_flow += f;
    }
    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        V = 2+n*m;
        adj.clear();
        adj.resize(V);
        board = vector<vector<int>>(n, vector<int>(m));
        capacity.assign(V, vector<int>(V, 0));
        flow.assign(V, vector<int>(V, 0));

        int sum = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> board[i][j];
                sum += board[i][j];
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                int here = get_id(i, j);

                if (is_set_a(i, j)) {
                    capacity[0][here] = board[i][j];
                    adj[0].push_back(here);
                    adj[here].push_back(0);
                    for (int k=0; k<4; ++k) {
                        int x = i+dx[k];
                        int y = j+dy[k];
                        if (in_range(x, y)) {
                            int there = get_id(x, y);
                            capacity[here][there] = INF;
                            adj[here].push_back(there);
                            adj[there].push_back(here);
                        }
                    }
                } else {
                    capacity[here][1] = board[i][j];
                    adj[1].push_back(here);
                    adj[here].push_back(1);
                }
            }
        }
        int max_flow = network_flow(0, 1);
        cout << sum - max_flow << endl;
    }

    return 0;
}

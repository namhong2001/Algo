#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
vector<vector<pair<int,int>>> adj;
int v, w;

int bellman(int src, int dst) {
    vector<int> dist(v, INF);
    dist[src] = 0;
    for (int iter=0; iter<v-1; ++iter) {
        for (int here=0; here<v; ++here) {
            for (pair<int,int> p : adj[here]) {
                int there = p.first;
                int weight = p.second;
                if (dist[there] > dist[here] + weight) {
                    dist[there] = dist[here] + weight;
                }
            }
        }
    }

    vector<vector<bool>> reachable(v, vector<bool>(v, false));
    for (int i=0; i<v; ++i) reachable[i][i] = true;
    for (int here=0; here<v; ++here) {
        for (pair<int,int> p : adj[here]) {
            int there = p.first;
            reachable[here][there] = true;
        }
    }
    for (int k=0; k<v; ++k) {
        for (int i=0; i<v; ++i) {
            for (int j=0; j<v; ++j) {
                reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
            }
        }
    }
    for (int here=0; here<v; ++here) {
        for (pair<int,int> p : adj[here]) {
            int there = p.first;
            int weight = p.second;
            if (dist[there] > dist[here] + weight) {
                if (reachable[src][here] && reachable[here][dst]) return -INF;
            }
        }
    }
    return dist[dst];
}

string to_str(int ans, int rev) {
    if (ans == -INF) return "INFINITY";
    if (ans > INF/2) return "UNREACHABLE";
    return to_string(ans * rev);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> w;
        adj.clear();
        adj.resize(v);
        for (int i=0; i<w; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
        }
        string ans = to_str(bellman(0, 1), 1);
        cout << ans << ' ';
        if (ans != "UNREACHABLE") {
            for (int i=0; i<v; ++i) {
                for (pair<int,int> &p : adj[i]) {
                    p.second *= -1;
                }
            }
            cout << to_str(bellman(0, 1), -1);
        }
        cout << endl;
    }
    return 0;
}

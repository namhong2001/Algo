#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<vector<int>> capacity, flow;
vector<unordered_set<int>*> conn;

const int src = 0;
const int sink = 1;
int V;


int network_flow() {
    int total = 0;
    while (true) {
        vector<int> parent(V, -1);
        parent[src] = src;
        queue<int> q;
        q.push(src);
        while (!q.empty() && parent[sink] == -1) {
            int here = q.front(); q.pop();
            for (int there=0; there<V; ++there) {
                if (capacity[here][there] - flow[here][there] > 0 &&
                    parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if (parent[sink] == -1) break;
        int f = INF;
        for (int p=sink; p!=src; p=parent[p]) {
            f = min(f, capacity[parent[p]][p]-flow[parent[p]][p]);
        }
        for (int p=sink; p!=src; p=parent[p]) {
            flow[parent[p]][p] += f;
            flow[p][parent[p]] -= f;
        }
        total += f;
    }
    return total;
}

int main() {
    int m, n;
    cin >> m >> n;
    V = n+m+2;
    capacity.assign(V, vector<int>(V, 0));
    flow.assign(V, vector<int>(V, 0));
    conn.assign(V, nullptr);
    for (int i=2; i<2+m; ++i) {
        conn[i] = new unordered_set<int>();
        conn[i]->insert(i);
    }

    for (int i=0; i<m; ++i) {
        int a;
        cin >> a;
        capacity[0][2+i] = a;
    }
    for (int i=0; i<n; ++i) {
        int c;
        cin >> c;
        unordered_set<int> *s = new unordered_set<int>();
        for (int j=0; j<c; ++j) {
            int k;
            cin >> k;
            k++;
            s->insert(conn[k]->begin(), conn[k]->end());
            conn[k] = s;
        }
        int b;
        cin >> b;
        for (int pig : *s) {
            capacity[pig][2+m+i] = INF;
        }
        capacity[2+m+i][1] = b;
    }
    cout << network_flow() << endl;

    return 0;
}

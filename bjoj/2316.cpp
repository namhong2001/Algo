#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<vector<int>> capacity, flow;
int n, p;
int v;


int networkflow(int s, int t) {
    int total = 0;
    while (true) {
        vector<int> parent(v, -1);
        queue<int> q;
        parent[s] = s;
        q.push(s);
        while (!q.empty() && parent[t] == -1) {
            int here = q.front(); q.pop();
            for (int there=0; there<v; ++there) {
                if (capacity[here][there] - flow[here][there] > 0 &&
                    parent[there] == -1) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        if (parent[t] == -1) break;
        int path_min = INF;
        for (int p=t; p!=s; p=parent[p]) {
            path_min = min(path_min, capacity[parent[p]][p]-flow[parent[p]][p]);
        }
        for (int p=t; p!=s; p=parent[p]) {
            flow[parent[p]][p] += path_min;
            flow[p][parent[p]] -= path_min;
        }
        total += path_min;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> p;
    v = 2*n-2;
    capacity = vector<vector<int>>(v, vector<int>(v, 0));
    flow = vector<vector<int>>(v, vector<int>(v, 0));
    for (int i=1; i<=n-2; ++i) {
        capacity[2*i][2*i+1] = 1;
    }

    while (p--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int ain = a > 1 ? (a-1)*2 : a;
        int aout = a > 1 ? (a-1)*2+1 : a;
        int bin = b > 1 ? (b-1)*2 : b;
        int bout = b > 1 ? (b-1)*2+1 : b;
        capacity[aout][bin] = INF;
        capacity[bout][ain] = INF;
    }
    cout << networkflow(0, 1) << endl;
    return 0;
}

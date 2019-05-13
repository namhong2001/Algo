#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int INF = 987654321;

vector<vector<pair<int,int>>> adj;


int n, m;
vector<int> dijkstra() {
    priority_queue<pair<int,int>> pq;
    vector<int> d(n, INF);
    vector<int> p(n, -1);
    d[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (cost > d[here]) continue;
        for (pair<int,int> t : adj[here]) {
            int there = t.first;
            int nc = t.second + cost;
            if (nc < d[there]) {
                d[there] = nc;
                pq.push({-nc, there});
                p[there] = here;
            }
        }
    }
    return p;
}


int main() {
    cin >> n >> m;
    adj = vector<vector<pair<int,int>>>(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> p = dijkstra();
    vector<pair<int,int>> ans;
    for (int i=0; i<n; ++i) {
        if (p[i] != -1) {
            ans.push_back({p[i], i});
        }
    }
    cout << ans.size() << '\n';
    for (pair<int,int> a : ans) {
        cout << a.first+1 << ' ' << a.second+1 << '\n';
    }

    return 0;
}

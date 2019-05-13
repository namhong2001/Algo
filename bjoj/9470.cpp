#include <iostream>
#include <vector>
#include <queue>
#include <utility>


using namespace std;

vector<vector<int>> adj;
vector<int> indegree;
vector<pair<int, int>> parent_strahler;
vector<int> strahler;

int k, m, p;

void solve() {
    queue<int> q;
    for (int i=1; i<=m; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            parent_strahler[i] = {0, 2};
        }
    }
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        if (parent_strahler[here].second >=2) {
            strahler[here] = parent_strahler[here].first + 1;
        } else {
            strahler[here] = parent_strahler[here].first;
        }
        for (int there : adj[here]) {
            if (--indegree[there] == 0) {
                q.push(there);
            }
            if (parent_strahler[there].first == strahler[here]) {
                parent_strahler[there].second++;
            } else if (parent_strahler[there].first < strahler[here]) {
                parent_strahler[there] = {strahler[here], 1};
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> k >> m >> p;
        adj = vector<vector<int>>(m+1);
        indegree = vector<int>(m+1, 0);
        parent_strahler = vector<pair<int,int>>(m+1, {0,0});
        strahler = vector<int>(m+1, 0);
        for (int i=0; i<p; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            indegree[b]++;
        }
        solve();
        cout << k << ' ' << strahler[m] << endl;
    }


    return 0;
}

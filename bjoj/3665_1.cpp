#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n;
int ranking[500];
bool adj[500][500];
int indegree[500];

void solve() {
    vector<int> ans;
    queue<int> q;
    for (int i=0; i<n; ++i) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    for (int i=0; i<n; ++i) {
        if (q.size() > 1) {
            cout << "?" << endl;
            return;
        } else if (q.empty()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        int here = q.front();
        q.pop();
        ans.push_back(here);
        for (int there=0; there<n; ++there) {
            if (adj[here][there]) {
                indegree[there]--;
                if (indegree[there] == 0) {
                    q.push(there);
                }
            }
        }
    }
    for (int i=0; i<n; ++i) {
        cout << ans[i]+1 << ' ';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(adj, false, sizeof(adj));

        cin >> n;

        for (int i=0; i<n; ++i) {
            cin >> ranking[i];
            indegree[ranking[i]-1] = i;
        }

        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int here = ranking[i]-1;
                int there = ranking[j]-1;
                adj[here][there] = true;
            }
        }
        int m;
        cin >> m;
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (adj[a][b]) {
                adj[a][b] = false;
                indegree[b]--;
                adj[b][a] = true;
                indegree[a]++;
            } else {
                adj[b][a] = false;
                indegree[a]--;
                adj[a][b] = true;
                indegree[b]++;
            }
        }
        solve();
    }
    return 0;
}

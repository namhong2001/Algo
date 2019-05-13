#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int>> adj;

vector<int> discovered;
vector<pair<int,int>> ans;
int counter;

int dfs(int parent, int here) {
    discovered[here] = counter++;
    int ret = discovered[here];

    for (int there : adj[here]) {
        if (there == parent) continue;
        if (discovered[there] == -1) {
            ret = min(ret, dfs(here, there));
        } else {
            ret = min(ret, discovered[there]);
        }
    }
    if (parent != here && ret >= discovered[here]) {
        ans.push_back({min(parent, here), max(parent, here)});
    }
    return ret;
}

void solve() {
    for (int i=1; i<discovered.size(); ++i) {
        if (discovered[i] == -1) {
            dfs(i, i);
        }
    }
}



int main() {
    int v, e;
    cin >> v >> e;
    adj = vector<vector<int>>(v+1);
    discovered = vector<int>(v+1, -1);
    counter = 0;
    ans = vector<pair<int,int>>();

    for (int i=0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve();
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (pair<int,int> edge : ans) {
        cout << edge.first << ' ' << edge.second << '\n';
    }

    return 0;
}


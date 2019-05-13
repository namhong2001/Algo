#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;

vector<int> discovered;
vector<int> ans;
int counter;

int dfs(int here, bool is_root) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int children_cnt = 0;
    bool is_cutvertex = false;

    for (int there : adj[here]) {
        if (discovered[there] == -1) {
            int subtree = dfs(there, false);
            children_cnt++;
            if (!is_root && subtree >= discovered[here]) {
                is_cutvertex = true;
            }
            ret = min(ret, subtree);
        } else {
            ret = min(ret, discovered[there]);
        }
    }

    if (is_cutvertex || (is_root && children_cnt >= 2)) {
        ans.push_back(here);
    }
    return ret;
}

void solve() {
    for (int i=1; i<discovered.size(); ++i) {
        if (discovered[i] == -1) {
            dfs(i, true);
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    adj = vector<vector<int>>(v+1);
    discovered = vector<int>(v+1, -1);
    counter = 0;
    ans = vector<int>();

    for (int i=0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve();
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int vertex : ans) {
        cout << vertex << ' ';
    }

    return 0;
}

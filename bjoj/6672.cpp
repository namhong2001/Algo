#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p, c;
vector<vector<int>> adj;
vector<int> discovered;

int counter;
int max_parts;
int dfs(int here, bool is_root) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int parts = is_root ? 0 : 1;
    for (int there : adj[here]) {
        if (discovered[there] == -1) {
            int sub_tree = dfs(there, false);
            if (sub_tree >= discovered[here]) parts++;
            ret = min(ret, sub_tree);
        } else {
            ret = min(ret, discovered[there]);
        }
    }
    max_parts = max(max_parts, parts);
    return ret;
}

int solve() {
    counter = 0;
    max_parts = 0;
    int ans = 0;
    for (int i=0; i<p; ++i) {
        if (discovered[i] == -1) {
            dfs(i, true);
            ans++;
        }
    }
    return ans + max_parts - 1;
}

int main() {
    while (true) {
        cin >> p >> c;
        if (p == 0 && c == 0) break;

        adj = vector<vector<int>>(p);
        discovered = vector<int>(p, -1);

        for (int i=0; i<c; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << solve() << endl;
    }
    return 0;
}

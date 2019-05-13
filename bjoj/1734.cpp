#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int ROOT = 1;
int n, e;
vector<vector<int>> adj;
vector<int> subgraph_range;
vector<int> discovered;
vector<int> connected;
vector<vector<int>> children;
set<pair<int,int>> bridge;
int counter = 0;


int dfs(int parent, int here) {
    discovered[here] = counter++;
    int &ret = connected[here] = discovered[here];
    for (int there : adj[here]) {
        if (discovered[there] == -1) {
            ret = min(ret, dfs(here, there));
            children[here].push_back(there);
        } else if (parent != there) {
            ret = min(ret, discovered[there]);
        }
    }
    if (ret >= discovered[here]) {
        bridge.insert({min(parent, here), max(parent, here)});
    }
    subgraph_range[here] = counter-1;
    return ret;
}

int in_range(int subgraph, int target_vertex) {
    int a = discovered[subgraph];
    int b = subgraph_range[subgraph];
    int dt = discovered[target_vertex];
    if (a <= dt && dt <= b) return 1;
    return 0;
}

string check_type1 (int a, int b, int g1, int g2) {
    if (bridge.find({min(g1, g2), max(g1, g2)}) == bridge.end()) return "yes";
    else {
        int subgraph = discovered[g1] > discovered[g2] ? g1 : g2;
        if (in_range(subgraph, a) ^ in_range(subgraph, b)) return "no";
    }
    return "yes";
}

string check_type2 (int a, int b, int c) {
    int a_root = ROOT;
    int b_root = ROOT;
    for (int child : children[c]) {
        if (in_range(child, a)) {
            a_root = child;
        }
        if (in_range(child, b)) {
            b_root = child;
        }
    }

    if (a_root == b_root) return "yes";
    else if (connected[a_root] < discovered[c] && connected[b_root] < discovered[c]) return "yes";
    return "no";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> e;
    subgraph_range = vector<int>(n+1, -1);
    discovered = vector<int>(n+1, -1);
    connected = vector<int>(n+1, -1);
    adj = vector<vector<int>>(n+1);
    children = vector<vector<int>>(n+1);
    for (int i=0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(ROOT, ROOT);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, g1, g2;
            cin >> a >> b >> g1 >> g2;
            cout << check_type1(a, b, g1, g2) << '\n';
        } else if (type == 2) {
            int a, b, c;
            cin >> a >> b >> c;
            cout << check_type2(a, b, c) << '\n';
        }
    }

    return 0;
}

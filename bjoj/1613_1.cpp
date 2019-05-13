#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}
void u(int a, int b) {
    a = f(a);
    b = f(b);
    r[b] = a;
}

int n, k;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> topol;
vector<int> topol_pos;
void dfs(int here) {
    visited[here] = true;
    for (int there : adj[here]) {
        if (!visited[there]) dfs(there);
    }
    topol.push_back(here);
}

void make_topol() {
    visited.assign(n, false);
    topol_pos.resize(n);
    for (int i=0; i<n; ++i) {
        if (!visited[i]) dfs(i);
    }
    reverse(topol.begin(), topol.end());
    for (int i=0; i<n; ++i) {
        topol_pos[topol[i]] = i;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    adj.resize(n);
    r.resize(n);
    for (int i=0; i<n; ++i) r[i] = i;
    while (k--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        u(a, b);
    }
    make_topol();
    int s;
    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (f(a) != f(b)) cout << 0 << '\n';
        else if (topol_pos[a] < topol_pos[b]) cout << -1 << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}

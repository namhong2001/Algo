#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> inputs;
vector<int> topological;
vector<bool> visited;

vector<int> root;
int get_root(int me) {
    if (root[me] == me) return me;
    return root[me] = get_root(root[me]);
}

void dfs(int here) {
    visited[here] = true;
    for (int there=0; there<n; ++there) {
        if (inputs[here][there] == '1' && get_root(there) == there && !visited[there]) {
            dfs(there);
        }
    }
    topological.push_back(here);
}

vector<int> topological_sort() {
    topological.clear();
    visited.assign(n, false);

    for (int here=0; here<n; ++here) {
        if (get_root(here) == here && !visited[here]) {
            dfs(here);
        }
    }
    reverse(topological.begin(), topological.end());
    return topological;
}

vector<pair<int, int>> solve() {
    root.resize(n);
    for (int i=0; i<n; ++i) root[i] = i;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (inputs[i][j] == '1' && inputs[j][i] == '1') {
                root[get_root(i)] = get_root(j);
            }
        }
    }

    vector<vector<int>> scc_vertices(n);
    for (int i=0; i<n; ++i) {
        scc_vertices[get_root(i)].push_back(i);
    }

    vector<int> topol = topological_sort();
    vector<vector<int>> parents(n);
    for (int i=0; i<topol.size(); ++i) {
        int here = topol[i];
        for (int j=i+1; j<topol.size(); ++j) {
            int there = topol[j];
            if (inputs[here][there] == '0') continue;

            vector<int> new_parents;
            for (int candi : parents[there]) {
                if (inputs[candi][here] == '1') continue;
                new_parents.push_back(candi);
            }
            new_parents.push_back(here);
            parents[there] = new_parents;
        }
    }

    vector<pair<int, int>> ans;
    for (vector<int> vertices : scc_vertices) {
        if (vertices.size() <= 1) continue;
        for (int i=0; i<vertices.size(); ++i) {
            int here = vertices[i];
            int there = i+1 < vertices.size() ? vertices[i+1] : vertices[0];
            ans.push_back({here, there});
        }
    }
    for (int i=0; i<n; ++i) {
        if (parents[i].empty()) continue;
        for (int parent : parents[i]) {
            ans.push_back({parent, i});
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        inputs.clear();
        inputs.resize(n);
        for (int i=0; i<n; ++i) {
            cin >> inputs[i];
        }
        vector<pair<int,int>> ans = solve();
        cout << ans.size() << '\n';
        for (pair<int,int> load : ans) {
            cout << load.first+1 << ' ' << load.second+1 << '\n';
        }
        cout << '\n';
    }
    return 0;
}

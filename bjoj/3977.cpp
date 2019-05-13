#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int scc_counter;
int vertex_counter;
vector<vector<int>> adj;
vector<vector<int>> scc_vertices;
vector<int> scc_id;
vector<int> discovered;
stack<int> st;
int n, m;

int find_scc(int here) {
    int ret = discovered[here] = vertex_counter++;
    st.push(here);

    for (int there : adj[here]) {
        if (discovered[there] == -1) {
            ret = min(ret, find_scc(there));
        } else if (scc_id[there] == -1) {
            ret = min(ret, discovered[there]);
        }
    }
    if (ret == discovered[here]) {
        vector<int> v_arr;
        while (true) {
            int v = st.top();
            st.pop();
            scc_id[v] = scc_counter;
            v_arr.push_back(v);
            if (v == here) break;
        }
        scc_vertices.push_back(v_arr);
        ++scc_counter;
    }
    return ret;
}

int dfs(int here, vector<bool> &visited) {
    visited[here] = true;
    int ret = 1;
    for (int there : adj[here]) {
        if (!visited[there]) {
            ret += dfs(there, visited);
        }
    }
    return ret;
}

vector<int> solve() {
    scc_counter = 0;
    vertex_counter = 0;
    scc_vertices.clear();
    scc_id = vector<int>(n, -1);
    discovered = vector<int>(n, -1);
    st = stack<int>();

    for (int i=0; i<n; ++i) {
        if (discovered[i] == -1) find_scc(i);
    }
    vector<bool> visited(n, false);
    int root = scc_vertices.back().front();
    int visited_count = dfs(root, visited);
    if (visited_count == n) return scc_vertices.back();
    else return vector<int>();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        adj = vector<vector<int>>(n);
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        vector<int> ans = solve();
        if (ans.empty()) cout << "Confused" << '\n';
        else {
            sort(ans.begin(), ans.end());
            for (int v : ans) {
                cout << v << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}

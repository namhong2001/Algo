#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int n, m;
vector<vector<int>> adj;
vector<int> discovered;
vector<int> scc_id;
stack<int> st;
int scc_counter;
int vertex_counter;

int dfs(int here) {
    int ret = discovered[here] = vertex_counter++;
    st.push(here);
    for (int there : adj[here]) {
        if (discovered[there] == -1) {
            ret = min(ret, dfs(there));
        } else if (scc_id[there] == -1) {
            ret = min(ret, discovered[there]);
        }
    }
    if (ret == discovered[here]) {
        while (true) {
            int v = st.top();
            st.pop();
            scc_id[v] = scc_counter;
            if (v == here) break;
        }
        ++scc_counter;
    }

    return ret;
}

vector<int> solve() {
    discovered = scc_id = vector<int>(n, -1);
    st = stack<int>();
    scc_counter = vertex_counter = 0;
    for (int i=0; i<n; ++i) {
        if (discovered[i] == -1) {
            dfs(i);
        }
    }

    vector<bool> has_outdegree(scc_counter, false);
    for (int here=0; here<n; ++here) {
        for (int there : adj[here])
        if (scc_id[here] != scc_id[there]) {
            has_outdegree[scc_id[here]] = true;
        }
    }
    vector<int> ans;
    for (int here=0; here<n; ++here) {
        if (!has_outdegree[scc_id[here]]) {
            ans.push_back(here);
        }
    }
    return ans;
}



int main() {
    while (true) {
        cin >> n;
        if (n == 0) return 0;

        adj = vector<vector<int>>(n);

        cin >> m;
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
        }
        vector<int> ans = solve();
        for (int v : ans) {
            cout << v+1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}

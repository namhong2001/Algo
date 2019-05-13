#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

int n, m, s, t;

int scc_counter;
int vertex_counter;
vector<vector<int>> adj;
vector<int> discovered;
vector<int> scc_id;
stack<int> st;
vector<set<int>> scc_adj;
vector<int> scc_vertices_cnt;
int t_scc = -1;

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
        int cnt = 0;
        while (true) {
            int v = st.top();
            st.pop();
            scc_id[v] = scc_counter;
            cnt++;
            for (int u : adj[v]) {
                if (scc_id[u] != -1 && scc_id[u] != scc_counter) {
                    scc_adj[scc_counter].insert(scc_id[u]);
                }
            }
            if (v == t) t_scc = scc_counter;
            if (v == here) break;
        }
        scc_vertices_cnt[scc_counter] = cnt;
        scc_counter++;
    }
    return ret;
}

int solve() {
    discovered = vector<int>(n, -1);
    scc_id = vector<int>(n, -1);
    scc_adj = vector<set<int>>(n);
    scc_vertices_cnt = vector<int>(n, 0);
    dfs(s);

    if (t_scc == -1) return 0;

    vector<int> critical_cost(scc_counter, 0);
    for (int here_scc=scc_counter-1; here_scc>=0; --here_scc) {
        critical_cost[here_scc] += scc_vertices_cnt[here_scc];
        for (int next_scc : scc_adj[here_scc]) {
            critical_cost[next_scc] = max(critical_cost[next_scc], critical_cost[here_scc]);
        }
    }
    return critical_cost[t_scc];
}


int main() {
    cin >> n >> m >> s >> t;
    s--;
    t--;
    adj = vector<vector<int>>(n);
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    cout << solve() << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> v_money;
vector<int> restaurants;
vector<int> discovered;
vector<int> scc_id;
stack<int> st;
int vertex_counter;
int scc_counter;


int n, m;
int s, p;

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

int solve() {
    discovered = vector<int>(n, -1);
    scc_id = vector<int>(n, -1);

    dfs(s);

    vector<vector<int>> scc_adj(scc_counter);

    for (int u=0; u<n; ++u) {
        if (scc_id[u] == -1) continue;

        vector<bool> used(scc_counter, false);
        for (int v : adj[u]) {
            if (scc_id[v] != scc_id[u] && !used[scc_id[v]]) {
                used[scc_id[v]] = true;
                scc_adj[scc_id[u]].push_back(scc_id[v]);
            }
        }
    }

    vector<int> scc_money(scc_counter, 0);
    for (int i=0; i<n; ++i) {
        if (scc_id[i] == -1) continue;
        scc_money[scc_id[i]] += v_money[i];
    }
    vector<bool> restaurant_scc(scc_counter, false);
    for (int restaurant : restaurants) {
        if (scc_id[restaurant] == -1) continue;
        restaurant_scc[scc_id[restaurant]] = true;
    }
    vector<int> critical_cost(scc_counter, 0);
    for (int i=scc_counter-1; i>=0; --i) {
        critical_cost[i] += scc_money[i];
        for (int scc_next : scc_adj[i]) {
            critical_cost[scc_next] = max(critical_cost[scc_next], critical_cost[i]);
        }
    }
    int ret = 0;
    for (int i=0; i<scc_counter; ++i) {
        if (restaurant_scc[i]) {
            ret = max(ret, critical_cost[i]);
        }
    }
    return ret;
}


int main() {
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    v_money = vector<int>(n);
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    for (int i=0; i<n; ++i) {
        cin >> v_money[i];
    }
    cin >> s >> p;
    s--;
    for (int i=0; i<p; ++i) {
        int a;
        cin >> a;
        a--;
        restaurants.push_back(a);
    }
    cout << solve() << endl;


    return 0;
}

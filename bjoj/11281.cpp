#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>


using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> discovered;
vector<int> scc_id;
stack<int> st;
int vertex_counter;
int scc_counter;

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
        scc_counter++;
    }
    return ret;
}

vector<int> solve() {
    discovered = scc_id = vector<int>(n*2, -1);
    for (int i=0; i<2*n; ++i) {
        if (discovered[i] == -1) {
            dfs(i);
        }
    }
    for (int i=0; i<2*n; i+=2) {
        if (scc_id[i] == scc_id[i+1]) {
            return vector<int>();
        }
    }
    vector<int> ans(n, -1);
    vector<pair<int,int>> order;
    for (int i=0; i<2*n; ++i) {
        order.push_back({-scc_id[i], i});
    }
    sort(order.begin(), order.end());

    for (pair<int,int> cur : order) {
        int here = cur.second;
        cout << here << endl;
        if (ans[here/2] != -1) continue;
        ans[here/2] = here%2;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int>>(2*n);
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        a = (abs(a)-1) * 2 + (a<0 ? 1 : 0);
        b = (abs(b)-1) * 2 + (b<0 ? 1 : 0);
        int not_a = a%2 ? a-1 : a+1;
        int not_b = b%2 ? b-1 : b+1;
        adj[not_a].push_back(b);
        adj[not_b].push_back(a);
    }
    vector<int> ans = solve();
    if (ans.empty()) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
        for (int a : ans) {
            cout << a << ' ';
        }
    }
    return 0;
}

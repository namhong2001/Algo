#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<int> scc_id;
vector<int> discovered;
stack<int> st;
int scc_counter;
int vertex_counter;

int l;

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


int solve() {
    scc_id = vector<int>(l, -1);
    discovered = vector<int>(l, -1);
    for (int i=0; i<l; ++i) {
        if (discovered[i] == -1) dfs(i);
    }
    for (int i=0; i<l; i+=2) {
        if (scc_id[i] == scc_id[i+1]) return 0;
    }
    return 1;
}


int main() {
    int n, m;
    cin >> n >> m;
    l = (n+m)*2;
    adj = vector<vector<int>>(l);
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<m; ++j) {
            int a = i*2;
            int not_a = a+1;
            int b = (n+j)*2;
            int not_b = b+1;
            if (s[j] == '#') {
                adj[a].push_back(b);
                adj[b].push_back(a);
                adj[not_a].push_back(not_b);
                adj[not_b].push_back(not_a);
            } else if (s[j] == '*') {
                adj[a].push_back(not_b);
                adj[b].push_back(not_a);
                adj[not_a].push_back(b);
                adj[not_b].push_back(a);
            }
        }
    }
    cout << solve() << endl;
    return 0;
}

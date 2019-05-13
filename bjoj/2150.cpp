#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int v, e;
int scc_counter;
int discovered_counter;
vector<int> scc_id;
vector<vector<int>> adj;
vector<int> discovered;
vector<vector<int>> scc_vertices;
stack<int> st;

int dfs(int here) {
    discovered[here] = discovered_counter++;
    int ret = discovered[here];
    st.push(here);
    for (int there : adj[here]) {
        if (discovered[there] == -1) {
            ret = min(ret, dfs(there));
        } else if (scc_id[there] == -1) {
            ret = min(ret, discovered[there]);
        }
    }
    if (ret == discovered[here]) {
        vector<int> vertices;
        while (true) {
            int vertex = st.top();
            st.pop();
            scc_id[vertex] = scc_counter;
            vertices.push_back(vertex);
            if (vertex == here) break;
        }
        scc_vertices.push_back(vertices);
        scc_counter++;
    }
    return ret;
}

void solve() {
    for (int i=0; i<v; ++i) {
        if (discovered[i] == -1) {
            dfs(i);
        }
    }
};

void print() {
    vector<bool> printed(v, false);

    cout << scc_vertices.size() << '\n';

    for (int i=0; i<v; ++i) {
        if (printed[i]) continue;
        int scc = scc_id[i];
        vector<int> &vertices = scc_vertices[scc];
        sort(vertices.begin(), vertices.end());
        for (int vertex : vertices) {
            cout << vertex+1 << ' ';
            printed[vertex] = true;
        }
        cout << "-1" << '\n';
    }
}


int main() {
    cin >> v >> e;
    adj = vector<vector<int>>(v);
    scc_id = vector<int>(v, -1);
    discovered = vector<int>(v, -1);

    for (int i=0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    solve();
    print();

    return 0;
}

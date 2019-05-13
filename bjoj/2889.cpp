#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <utility>

using namespace std;

int n, e;
vector<unordered_map<int, int>> adj; // adj_node, edge_id
vector<int> ans;
vector<pair<int, int>> edges;
vector<int> degree;

void euler(int here) {
    int cafe_id=0;
    stack<pair<int,int>> st;
    st.push({here, -1});
    while (!st.empty()) {
        int here, edge_id;
        tie(here, edge_id) = st.top();
        if (!adj[here].empty()) {
            int there, next_edge;
            tie(there, next_edge) = *adj[here].begin();
            st.push({there, next_edge});
            adj[here].erase(there);
            adj[there].erase(here);
            degree[here]--;
            degree[there]--;
        } else {
            st.pop();
            if (edge_id != -1) {
                ans[edge_id] = cafe_id;
                cafe_id ^= 1;
            }
        }
    }
}

int main() {
    cin >> n >> e;
    adj = vector<unordered_map<int, int>>(n+2);
    degree = vector<int>(n+2, 0);
    for (int i=0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
        adj[a].insert({b, i});
        adj[b].insert({a, i});
        degree[a]++;
        degree[b]++;
    }
    for (int i=1; i<=n; ++i) {
        if (degree[i]%2 == 1) {
            edges.push_back({i, n+1});
            int edge_id = edges.size()-1;
            adj[i].insert({n+1, edge_id});
            adj[n+1].insert({i, edge_id});
            degree[i]++;
            degree[n+1]++;
        }
    }
    ans = vector<int>(edges.size(), 0);
    if (degree[n+1] > 0) {
        euler(n+1);
    }
    for (int i=1; i<=n; ++i) {
        if (degree[i] >= 4) {
            euler(i);
        }
    }
    for (int i=1; i<=n; ++i) {
        if (degree[i] > 0) {
            vector<int> root_edges;
            for (pair<int,int> edge : adj[i]) {
                root_edges.push_back(edge.second);
            }
            euler(i);
            if (ans[root_edges[0]] == ans[root_edges[1]]) {
                cout << '0';
                return 0;
            }
        }
    }
    for (int i=0; i<e; ++i) {
        cout << ans[i]+1 << '\n';
    }
}

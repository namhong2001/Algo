#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <utility>

using namespace std;

int n, e;
vector<int> ans;
vector<pair<int, int>> edges;
vector<vector<int>> edges_of_node;
vector<int> initial_degree;
vector<bool> edge_used;


void euler(int here) {
    int cafe_id=0;
    stack<pair<int,int>> st;
    st.push({here, -1});
    while (!st.empty()) {
        int here, edge_id;
        tie(here, edge_id) = st.top();
        int next_edge = -1;
        while (!edges_of_node[here].empty()) {
            int candi = edges_of_node[here].back();
            if (!edge_used[candi]) {
                next_edge = candi;
                break;
            }
            edges_of_node[here].pop_back();
        }

        if (next_edge != -1) {
            int there = edges[next_edge].first + edges[next_edge].second - here;
            st.push({there, next_edge});
            edge_used[next_edge] = true;
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
    initial_degree = vector<int>(n+2, 0);
    edges_of_node = vector<vector<int>>(n+2);
    for (int i=0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
        edges_of_node[a].push_back(i);
        edges_of_node[b].push_back(i);
        initial_degree[a]++;
        initial_degree[b]++;
    }
    for (int i=1; i<=n; ++i) {
        if (initial_degree[i]%2 == 1) {
            edges.push_back({i, n+1});
            int edge_id = edges.size()-1;
            edges_of_node[i].push_back(edge_id);
            edges_of_node[n+1].push_back(edge_id);
        }
    }
    ans = vector<int>(edges.size(), 0);
    edge_used = vector<bool>(edges.size(), false);
    if (!edges_of_node[n+1].empty()) {
        euler(n+1);
    }
    for (int i=1; i<=n; ++i) {
        if (edges_of_node[i].size() >= 4) {
            euler(i);
        }
    }
    for (int i=1; i<=n; ++i) {
        if (!edges_of_node[i].empty()) {
            vector<int> root_edges = edges_of_node[i];
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


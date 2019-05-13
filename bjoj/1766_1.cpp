#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[32001];
int indegree[32001];

vector<int> topological_sort() {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=1; i<=n; ++i) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int here = pq.top();
        pq.pop();
        ans.push_back(here);

        for (int next : adj[here]) {
            if (--indegree[next] == 0) {
                pq.push(next);
            }
        }
    }
    return ans;
}


int main() {
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    vector<int> ans = topological_sort();
    for (int here : ans) {
        cout << here << ' ';
    }

    return 0;
}

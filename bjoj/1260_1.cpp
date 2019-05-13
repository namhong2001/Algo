#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


const int N_MAX = 1000;
bool visited[N_MAX+1];
vector<int> edges[N_MAX+1];


void dfs(int me) {
    cout << me << ' ';
    visited[me] = true;
    for (int child : edges[me]) {
        if (visited[child]) continue;
        dfs(child);
    }
};

void bfs(int root) {
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        int me = que.front();
        que.pop();
        if (visited[me]) continue;
        cout << me << ' ';
        visited[me] = true;
        for (auto child : edges[me]) {
            if (visited[child]) continue;
            que.push(child);
        }
    }
}


int main() {
    int n, m, v;
    cin >> n >> m >> v;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=1; i<=n; ++i) {
        sort(edges[i].begin(), edges[i].end());
    }
    memset(visited, false, sizeof(visited));
    dfs(v);
    cout << endl;
    memset(visited, false, sizeof(visited));
    bfs(v);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int> edge[], bool flag[], int v) {
    cout << v << ' ';
    flag[v] = true;

    for (auto i : edge[v]) {
        if (!flag[i]) {
            dfs(edge, flag, i);
        }
    }
}

void bfs(vector<int> edge[], bool flag[], vector<int> &pre) {
    vector<int> visit;
    for (auto i : pre) {
        if (!flag[i]) {
            cout << i << ' ';
            flag[i] = true;
            visit.push_back(i);
        }
    }
    vector<int> next;
    for (auto i : visit) {
        for (auto j : edge[i]) {
            if (!flag[j]) {
                next.push_back(j);
            }
        }
    }
    if (next.size() > 0) {
        bfs(edge, flag, next);
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> edge[n+1];
    while(m--) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (auto &i : edge) {
        sort(i.begin(), i.end());
    }

    bool dfs_flag[n+1] = {false};
    bool bfs_flag[n+1] = {false};
    dfs(edge, dfs_flag, v);
    cout << '\n';
    vector<int> bfs_v;
    bfs_v.push_back(v);
    bfs(edge, bfs_flag, bfs_v);
    return 0;
}

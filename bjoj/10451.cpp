#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[1001];
bool visited[1001];

void dfs(int here) {
    visited[here] = true;
    int there = arr[here];
    if (!visited[there]) dfs(there);
}

int dfs_all(int n) {
    int ret = 0;
    for (int i=1; i<=n; ++i) {
        if (!visited[i]) {
            dfs(i);
            ++ret;
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; ++i) {
            cin >> arr[i];
        }
        memset(visited, false, sizeof(visited));
        cout << dfs_all(n) << endl;
    }

    return 0;
}

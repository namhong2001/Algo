#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int ranking[500];
bool adj[500][500];
bool visited[500];

void dfs(int here, vector<int> &ans) {
    visited[here] = true;
    for (int there=0; there<n; ++there) {
        if (adj[here][there] && !visited[there]) {
            dfs(there, ans);
        }
    }
    ans.push_back(here);
}

vector<int> topological_sort() {
    vector<int> ans;
    for (int i=0; i<n; ++i) {
        if (!visited[i]) {
            dfs(i, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool check_impossible(vector<int> &ans) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<i; ++j) {
            int here = ans[i];
            int prev = ans[j];
            if (adj[here][prev]) {
                return true;
            }
        }
    }
    return false;
}

bool check_ambiguous(vector<int> &ans) {
    for (int i=0; i<n-1; ++i) {
        int here = ans[i];
        int next = ans[i+1];
        if (!adj[here][next]) {
            return true;
        }
    }
    return false;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(adj, false, sizeof(adj));
        memset(visited, false, sizeof(visited));


        cin >> n;

        for (int i=0; i<n; ++i) {
            cin >> ranking[i];
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int here = ranking[i]-1;
                int there = ranking[j]-1;
                adj[here][there] = true;
            }
        }
        int m;
        cin >> m;
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (adj[a][b]) {
                adj[a][b] = false;
                adj[b][a] = true;
            } else {
                adj[b][a] = false;
                adj[a][b] = true;
            }
        }

        vector<int> ans = topological_sort();
        if (check_impossible(ans)) {
            cout << "IMPOSSIBLE" << endl;
        } else if (check_ambiguous(ans)) {
            cout << "?" << endl;
        } else {
            for (int order : ans) {
                cout << order+1 << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}

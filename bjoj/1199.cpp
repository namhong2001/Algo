#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> degree;

void dfs(int here, vector<int> &ans) {
    for (int there=0; there<adj.size(); ++there) {
        if (adj[here][there] > 0) {
            adj[here][there]--;
            adj[there][here]--;
            dfs(there, ans);
        }
    }
    ans.push_back(here);
}

vector<int> euler() {
    vector<int> ans;
    for (int i=0; i<degree.size(); ++i) {
        if (degree[i] > 0) {
            dfs(i, ans);
            break;
        }
    }
    return ans;
}

bool check_euler() {
    for (int i=0; i<degree.size(); ++i) {
        if (degree[i]%2) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n, vector<int>(n, 0));
    degree = vector<int>(n, 0);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> adj[i][j];
            degree[i] += adj[i][j];
        }
    }
    if (!check_euler()) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans = euler();
    for (int here : ans) {
        cout << here+1 << ' ';
    }
    return 0;
}

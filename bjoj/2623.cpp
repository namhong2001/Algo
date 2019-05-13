#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool adj[1001][1001];
int indegree[1001];

vector<int> solve() {
    queue<int> q;
    vector<int> ans;
    for (int i=1; i<=n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    for (int i=0; i<n; ++i) {
        if (q.empty()) return vector<int>();

        int here = q.front();
        q.pop();
        ans.push_back(here);
        for (int there=1; there<=n; ++there) {
            if (adj[here][there]) {
                if (--indegree[there] == 0) {
                    q.push(there);
                }
            }

        }
    }
    return ans;
}

int main() {

    cin >> n >> m;
    while (m--) {
        int c;
        cin >> c;
        vector<int> arr(c);
        for (int i=0; i<c; ++i) {
            cin >> arr[i];
        }
        for (int i=0; i<c; ++i) {
            for (int j=i+1; j<c; ++j) {
                if (!adj[arr[i]][arr[j]]) {
                    adj[arr[i]][arr[j]] = true;
                    indegree[arr[j]]++;
                }
            }
        }
    }
    vector<int> ans = solve();
    if (ans.empty()) cout << '0' << endl;
    else {
        for (int here : ans) {
            cout << here << endl;
        }
    }

    return 0;
}

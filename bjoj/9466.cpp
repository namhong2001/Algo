#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> sel;
vector<int> indegree;

int n;

int solve() {
    int cnt = 0;
    queue<int> q;
    for (int i=0; i<n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            cnt++;
        }
    }
    while (!q.empty()) {
        int here = q.front();
        int there = sel[here];
        q.pop();
        if (--indegree[there] == 0) {
            q.push(there);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        sel = vector<int>(n);
        indegree = vector<int>(n, 0);
        for (int i=0; i<n; ++i) {
            cin >> sel[i];
            sel[i]--;
            indegree[sel[i]]++;
        }
        cout << solve() << endl;
    }

    return 0;
}

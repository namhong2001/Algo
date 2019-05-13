#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;


int n, m;
vector<map<int,int>> adj;
vector<int> indegree;
vector<map<int,int>> parts;

void solve() {
    queue<int> q;
    for (int i=1; i<=n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            parts[i][i] = 1;
        }
    }
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (auto there : adj[here]) {
            int there_id = there.first;
            int there_cnt = there.second;
            for (auto part : parts[here]) {
                int part_id = part.first;
                int part_cnt = part.second;

                if (parts[there_id].find(part_id) == parts[there_id].end()) {
                    parts[there_id][part_id] = 0;
                }
                parts[there_id][part_id] += there_cnt*part_cnt;
            }
            if (--indegree[there_id] == 0) {
                q.push(there_id);
            }
        }

    }
}


int main() {
    cin >> n >> m;

    adj = vector<map<int,int>>(n+1);
    indegree = vector<int>(n+1, 0);
    parts = vector<map<int,int>>(n+1);

    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;
        adj[y][x] = k;
        indegree[x]++;
    }
    solve();

    for (auto part : parts[n]) {
        cout << part.first << ' ' << part.second << endl;

    }


    return 0;
}

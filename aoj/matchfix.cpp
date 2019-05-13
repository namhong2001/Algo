#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int n, m;
int V;
vector<int> wins;
vector<vector<int>> capacity;
vector<vector<int>> flow;
vector<pair<int,int>> match;
int total_flow = 0;

int network_flow(int s, int t) {
    while (true) {
        vector<int> parent(V, -1);
        queue<int> q;
        parent[s] = s;
        q.push(s);
        while (!q.empty() && parent[t] == -1) {
            int here = q.front();
            q.pop();
            for (int there=0; there<V; ++there) {
                if (capacity[here][there] - flow[here][there] > 0 &&
                    parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if (parent[t] == -1) break;
        int amount = INF;
        for (int p=t; p!=s; p=parent[p]) {
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }
        for (int p=t; p!=s; p=parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        total_flow += amount;
    }
    return total_flow;
}


bool can_win_with(int total_wins) {
    if (*max_element(wins.begin()+1, wins.end()) >= total_wins) return false;
    for (int i=0; i<n; ++i) {
        int max_win = i == 0 ? total_wins : total_wins-1;
        capacity[2+m+i][1] = max_win - wins[i];
    }
    return network_flow(0, 1) == m && flow[2+m][1] == total_wins - wins[0];
}

void make_graph() {
    V = 2 + m + n;
    capacity.assign(V, vector<int>(V, 0));
    flow.assign(V, vector<int>(V, 0));
    for (int i=0; i<m; ++i) {
        capacity[0][2+i] = 1;
        int a = match[i].first, b = match[i].second;
        capacity[2+i][2+m+a] = 1;
        capacity[2+i][2+m+b] = 1;
    }
}

int solve() {
    int start = *max_element(wins.begin(), wins.end());
    for (int ans=start; ans<=start+m; ++ans) {
        if (can_win_with(ans)) return ans;
    }
    return -1;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        // init
        wins.clear();
        capacity.clear();
        flow.clear();
        match.clear();
        total_flow = 0;

        cin >> n >> m;
        for (int i=0; i<n; ++i) {
            int a;
            cin >> a;
            wins.push_back(a);
        }
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            match.push_back({a, b});
        }
        make_graph();
        cout << solve() << '\n';
    }

    return 0;
}

